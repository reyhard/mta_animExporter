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
	label versionLabel "v0.0.1"
	label authorLabel "Author: Redphoenix"
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
				for t = animationRange.start to animationRange.end do
				(
					animate on
					(
						at time t
						(
							if t == 1 then
							(	
								startPosition = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).pos
							)
							print ("Frame: "+t as string)
							format "\n %" ("Frame: "+t as string) to:FrameDataTextFile
							if frameExporter_parentObject != undefined then
							(
								relativePosition = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).pos
								-- round
								relativeLength = length (relativePosition - startPosition)
								relativeLength = (round_to relativeLength 5) as float
								if relativeLength > 0 then
								(
									startPosition2 = relativePosition
								)
								relativePosition = relativePosition - startPosition
								relativePosition = [(round_to relativePosition.x 5) as float,(round_to relativePosition.y 5) as float,(round_to relativePosition.z 5) as float]
								relativePosition = relativePosition as string
								if relativeLength > 0 then
								(
									startPosition = startPosition2
								)
								--relativePosition = substituteString relativePosition "[" ""
								--relativePosition = substituteString relativePosition "]" ""
								format "\n%" (relativePosition as string) to:FrameDataTextFile
								format " start pos: %" (startPosition as string) to:FrameDataTextFile
								format " length: %" (relativeLength as string) to:FrameDataTextFile
								relativeRotation = ((frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).rotation) as eulerAngles
								relativeRotation = relativeRotation as string
								relativeRotation = substituteString relativeRotation "(eulerAngles " ""
								relativeRotation = substituteString relativeRotation ")" ""
								-- format "%\n" (relativeRotation as string) to:FrameDataTextFile
							)						
							-- print ($.position as string) 
							-- print ($.rotation as string) 
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