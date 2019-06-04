ClearListener()

global exportFrameDataMainUIFloater
if exportFrameDataMainUIFloater!=undefined then (
    closeRolloutFloater exportFrameDataMainUIFloater
)

-- Misc Variables
UIHeight = 505
UIWidth = 200

buttonHeight = 50
buttonWidth = 170

frameExporter_savePath = ""
frameExporter_defaultCenter = "model center"
frameExporter_parentObject = undefined
frameExporter_childObject = undefined
frameExporter_modelCenter = (getNodeByName frameExporter_defaultCenter) 
frameExporter_ID_scale = 0
frameExporter_ID_source = 1
frameExporter_ID_savePath = 2

-- Scale of our max rig  
rigScale = 10

-- Attempt to read some default values if model center is present
if frameExporter_modelCenter != undefined then
(
	if(getAppData frameExporter_modelCenter frameExporter_ID_scale  != undefined)then(
		rigScale = (getAppData frameExporter_modelCenter frameExporter_ID_scale ) as float
	)
)
frameExporter_source = "reloadMagazine.0"
frameExporter_range = [0.1,1000,rigScale]

-- Main UI
rollout exportFrameDataMainUI "Export Frame Data"
(
	label mainLabel "Frame Exporter" 
	label versionLabel "v0.9.0"
	label authorLabel "Author: Redphoenix and Reyhard"
	-- Model Params group
	
	group "Model params" 
	(
		spinner scaleFactor "Scale: " range:frameExporter_range type:#float align:#left offset:[0,0]
		edittext animationSource "Source:" text:frameExporter_source fieldWidth:120 height:18 labelOnTop: true
		pickbutton pickCenter "Model center: model center" width:buttonWidth height:buttonHeight offset:[0,10] \
		tooltip: "By default script looks for object called as \"model center\". This object respresents [0,0,0] position of your model"
		pickbutton pickParent "--Parent Object--" width:buttonWidth height:buttonHeight \
		tooltip: "If your bone is attached to something in model.cfg then use this button otherwise model center will be used"
		pickbutton pickChild "--Child Object--" width:buttonWidth height:buttonHeight \
		tooltip: ""	
	)
	-- Save Params group
	group "Save params" 
	(
		edittext savePathEdit "Save path:" text:frameExporter_savePath fieldWidth:160 height:18 labelOnTop: true readOnly: false
		button pickSavePath "Pick save path" width:buttonWidth height:buttonHeight
		button exportTxTFile "Start Exporting!" width:buttonWidth height:buttonHeight
	)
	
	-- Functions
	fn round_to val n =
	(
		local mult = 10.0 ^ n
		(floor ((val * mult) + 0.5)) / mult
	)
	fn round_vector_to vec n =
	(
		[(round_to vec.x 5) as float,(round_to vec.y 5) as float,(round_to vec.z 5) as float]
	)
	fn divide_vector vec n =
	(
		[(vec.x / n) as float,(vec.y / n) as float,(vec.z / n) as float]
	)
	fn remove_brackets str =
	(
		str = substituteString str "[" ""
		str = substituteString str "]" ""
	)
	fn writeAngleOutput angleDifference childStr frameName weaponRealtivePosition FrameDataTextFile vectorDirStr =
	(
		local vectorPosition = round_vector_to weaponRealtivePosition 4 
		vectorPosition = vectorPosition as string
		vectorPosition = remove_brackets vectorPosition  
		-- Compose string & save it to file
		format "\n TRANSFORM_ROTATION(%,%,%,%,%,%)" (childStr) (frameExporter_source) (frameName) (angleDifference as string) (vectorPosition) (vectorDirStr) to:FrameDataTextFile
		true
	)

	-- Actions
	on scaleFactor changed val do 
	(
		global rigScale = val
		setAppData frameExporter_modelCenter 0 (val as string)
	)
	on animationSource changed val do
	(
		frameExporter_source = val
		if frameExporter_childObject != undefined then
		(
			setAppData frameExporter_childObject frameExporter_ID_source val
		)
	)
	on pickCenter picked center do
	(
		pickCenter.text = "Model center: " + center.name
		global frameExporter_modelCenter = center
	)	
		
	on pickParent picked parent do
	(
		pickParent.text = "Parent: " + parent.name
		global frameExporter_parentObject = parent
	)
	
	on pickChild picked child do
	(
		pickChild.text = "Child: " + child.name
		global frameExporter_childObject = child
		
		if frameExporter_modelCenter == undefined then
		(
			return false
		)
		-- Grab local data from children
			print ("get data" + (getAppData frameExporter_modelCenter frameExporter_ID_source) as string )
		if(getAppData frameExporter_childObject frameExporter_ID_source  != undefined)then(
			frameExporter_source = (getAppData frameExporter_childObject frameExporter_ID_source )
			animationSource.text = frameExporter_source
		)
		if(getAppData frameExporter_childObject frameExporter_ID_savePath  != undefined)then(
			frameExporter_savePath = (getAppData frameExporter_childObject frameExporter_ID_savePath )
			savePathEdit.text = frameExporter_savePath
		)

	)
	on savePathEdit changed val do
	(
		frameExporter_source = val
		if frameExporter_childObject != undefined then
		(
			setAppData frameExporter_childObject frameExporter_ID_savePath val
		)
	)
	on pickSavePath pressed do
	(
		local savePath = getSaveFilename caption:"Save Frame Data to..."  types:"Text File(*.hpp)|*.hpp|Text file(*.txt)|*.txt|All|*.*|"
		if savePath != undefined then
		(
			savePathEdit.text = savePath
			print "done"
			if frameExporter_childObject != undefined then
			(
				setAppData frameExporter_childObject frameExporter_ID_savePath savePath
			)
		)
	)

	on exportTxTFile pressed do
	(
		if frameExporter_modelCenter == undefined then
		(
			messagebox "Please select a model center" title:"No model center"
			return false
		)
		frameExporter_modelCenter = (getNodeByName frameExporter_defaultCenter) 
		if frameExporter_parentObject == undefined then
		(
			frameExporter_parentObject = frameExporter_modelCenter
		)
		if frameExporter_parentObject != undefined then
		(
			if frameExporter_childObject != undefined then
			(
				if savePath == "" then
				(
					frameExporter_savePath = getSaveFilename caption:"Save Frame Data to..."  types:"Text File(*.txt)|*.txt|All|*.*|"
				)
				FrameDataTextFile = createfile (frameExporter_savePath)
				startPosition = [0,0,0]
				weaponRealtivePosition = [0,0,0]
				lastRotX = 0
				lastRotY = 0
				lastRotZ = 0
				childStr = (frameExporter_childObject.name) as string
				oldTransform = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform))
				
				start = true

				for t = animationRange.start to animationRange.end do
				(
					animate on
					(
						at time t
						(
							if frameExporter_parentObject != undefined then
							(
								-- Get start position. It will serve as our reference position
								if start then
								(	
									oldTransform = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform))
									startPosition = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).pos
									-- Adjust size of vector to our scale
									startPosition = divide_vector startPosition rigScale
									weaponRealtivePosition = (frameExporter_childObject.transform * (inverse frameExporter_modelCenter.transform)).pos
									weaponRealtivePosition = divide_vector weaponRealtivePosition rigScale
									start = false
								)

								currentTransform = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform))
								-- Get translation
								-- If there is change frame by frame then list animation in output file
								relativePosition = currentTransform.pos
								-- Adjust size of vector to our scale
								relativePosition = divide_vector relativePosition rigScale
								relativeLength = length (relativePosition - startPosition) 
								-- Rounded and then 
								relativeLength = (round_to relativeLength 5) as float 
								frameName = t as string;
								frameName = substituteString frameName "f" ""
								if relativeLength > 0 then
								(
									-- Get frame by frame movement
									vectorDirection = relativePosition - startPosition
									
									-- Disabled. Matrix operations are stacked and this method needs improvment - as a workaround translation is stored in separate bone
									-- weaponRealtivePosition = weaponRealtivePosition + vectorDirection

									startPosition = relativePosition

									vectorPosition = round_vector_to relativePosition 5
									vectorDirection = round_vector_to vectorDirection 5
									vectorPosition = remove_brackets (vectorPosition as string)
									vectorDirection = remove_brackets (vectorDirection as string) 
									-- Compose string and save it to file
									format "\n TRANSFORM_TRANSLATION(%,%,%,%,%,%)" (childStr) (frameExporter_source) (frameName) (relativeLength as string) (vectorPosition) (vectorDirection) to:FrameDataTextFile
								)

								-- Get rotations and save them as macro
								-- Do comparsion between current and previous (from frame before) then output result as angle axis which Arma is using for everything
								relativeRotation = ( (currentTransform * (inverse oldTransform)).rotation) as angleAxis
								roundedAngle = round_to relativeRotation.angle 4
								-- print ((relativeRotationVec) as string + " rotation:" + (currentTransform) as string)
								if roundedAngle > 0 then
								(
									relativeRotationVec = round_vector_to relativeRotation.axis 3
									-- We need to scale up vector before transforming by matrix
									relativeRotationVec =  divide_vector (relativeRotationVec) 0.1
									-- Transform vector by current local transformation matrix. (aka converting to transform space)
									relativeRotationVec = divide_vector (relativeRotationVec *  (matrix3 currentTransform.row1 currentTransform.row2 currentTransform.row3 [0,0,0])) 10
									relativeRotationVec = round_vector_to relativeRotationVec 3
									directionVectorStr = remove_brackets (relativeRotationVec as string)
									output_string = writeAngleOutput roundedAngle childStr frameName weaponRealtivePosition FrameDataTextFile directionVectorStr
								)
								
								oldTransform = currentTransform
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
