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
	
	on exportTxTFile pressed do
	(
		if frameExporter_parentObject != undefined then
		(
			if frameExporter_childObject != undefined then
			(
				savePath = getSaveFilename caption:"Save Frame Data to..."  types:"Text File(*.txt)|*.txt|All|*.*|"
				FrameDataTextFile = createfile (savePath)
				for t = animationRange.start to animationRange.end do
				(
					animate on
					(
						at time t
						(
							print ("Frame: "+t as string)
							if frameExporter_parentObject != undefined then
							(
								relativePosition = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).pos
								relativePosition = relativePosition as string
								relativePosition = substituteString relativePosition "[" ""
								relativePosition = substituteString relativePosition "]" ""
								format "test  %\n" (relativePosition as string) to:FrameDataTextFile
								relativeRotation = ((frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).rotation) as eulerAngles
								relativeRotation = relativeRotation as string
								relativeRotation = substituteString relativeRotation "(eulerAngles " ""
								relativeRotation = substituteString relativeRotation ")" ""
								format "%\n" (relativeRotation as string) to:FrameDataTextFile
							)						
							--print ($.position as string) + "test3"
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