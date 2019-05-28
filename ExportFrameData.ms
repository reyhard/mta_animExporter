ClearListener()

global exportFrameDataMainUIFloater
try(removeRollout exportFrameDataMainUIFloater)catch()

-- Misc Variables
UIHeight = 250
UIWidth = 180

buttonHeight = 50
buttonWidth = 150


frameExporter_parentObject = undefined
frameExporter_childObject = undefined

--
rollout exportFrameDataMainUI "Export Frame Data"
(
	label mainLabel "Frame Exporter" 
	label versionLabel "v0.0.3"
	label authorLabel "Author: Redphoenix & Reyhard"
	pickbutton pickParent "--Parent Object--" width:buttonWidth height:buttonHeight
	pickbutton pickChild "--Child Object--" width:buttonWidth height:buttonHeight
	
	label misc01 "-------------------------------------------------"
	
	button exportTxTFile "Start Exporting!" width:buttonWidth height:buttonHeight
	
	-- Do stuff below
	on pickParent picked parent do
	(
		pickParent.text = "Parent: " + parent.name
		global frameExporter_parentObject = parent
	)
	
	on pickChild picked child do
	(
		pickChild.text = "Child: " + child.name
		global frameExporter_childObject = child
	)
	-- Function to round values, accepts 2 paramters: value and precision
	fn round_to val n =
	(
		local mult = 10.0 ^ n
		(floor ((val * mult) + 0.5)) / mult
	)
	on exportTxTFile pressed do
	(
		if frameExporter_parentObject != undefined then
		(
			if frameExporter_childObject != undefined then
			(
				-- savePath = getSaveFilename caption:"Save Frame Data to..."  types:"Text File(*.txt)|*.txt|All|*.*|"
				-- Save it to test file to speed up debuging
				savePath = "C:\Users\\reyhard\Desktop\\testexp.txt"
				FrameDataTextFile = createfile (savePath)
				startPosition = [0,0,0]
				childStr = frameExporter_childObject.name 
				for t = animationRange.start to animationRange.end do
				(
					animate on
					(
						at time t
						(
							-- Get start position. It will serve as our reference position
							if t == 1 then
							(	
								startPosition = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).pos
							)
							print ("Frame: "+ t as string)
							if frameExporter_parentObject != undefined then
							(
								-- Get translation
								-- If there is change frame by frame then list animation in output file. Rotations are listed in separate file
								relativePosition = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).pos
								relativeLength = length (relativePosition - startPosition)
								relativeLength = (round_to relativeLength 5) as float
								if relativeLength > 0 then
								(
									frameName = t as string;
									frameName = substituteString frameName "f" ""
									-- Using macro to generate it
									format "\n %" ("TRANSFORM_TRANSLATION("+ childStr as string + ","+ frameName as string) to:FrameDataTextFile

									changeVector = relativePosition - startPosition
									changeVector = relativePosition + changeVector
									changeVector = [(round_to changeVector.x 5) as float,(round_to changeVector.y 5) as float,(round_to changeVector.z 5) as float]
									changeVector = changeVector as string

									startPosition = relativePosition
									format ",%" (relativeLength as string) to:FrameDataTextFile

									relativePosition = [(round_to relativePosition.x 5) as float,(round_to relativePosition.y 5) as float,(round_to relativePosition.z 5) as float]
									relativePosition = relativePosition as string
									relativePosition = substituteString relativePosition "[" ""
									relativePosition = substituteString relativePosition "]" ""
									format ",%" (relativePosition as string) to:FrameDataTextFile

									changeVector = substituteString changeVector "[" ""
									changeVector = substituteString changeVector "]" ""
									format ",%)" (changeVector as string) to:FrameDataTextFile
									
									-- Rotation macro
									relativeRotation = ((frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).rotation) as eulerAngles
									relativeRotation = relativeRotation as string
									relativeRotation = substituteString relativeRotation "(eulerAngles " ""
									relativeRotation = substituteString relativeRotation ")" ""
									-- format "%\n" (relativeRotation as string) to:FrameDataTextFile
								)
								-- TODO: Rotation should be listed in separate macro
							)						
						)
					)
				)			
				close FrameDataTextFile
				free FrameDataTextFile
			)
			else
			(
				messagebox "Please select child" title:"No Child"
			)
		)
		else
		(
			messagebox "Please select a parent" title:"No Parent"
		)
	)
)

 
exportFrameDataMainUIFloater = newrolloutfloater "Export Frame Data" UIWidth UIHeight
addRollout exportFrameDataMainUI exportFrameDataMainUIFloater border:false