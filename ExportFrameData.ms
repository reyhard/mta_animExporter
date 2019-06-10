ClearListener()

global exportFrameDataMainUIFloater
if exportFrameDataMainUIFloater!=undefined then (
    closeRolloutFloater exportFrameDataMainUIFloater
)

-- Misc Variables
UIHeight = 525
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
frameExporter_modelCenterString = "Model center: model center"
frameExporter_dummy = false
frameExporter_addHeader = true
frameExporter_header = "#define TOTAL_FRAMES (%/1)
#define FRAME(fr) (fr/TOTAL_FRAMES)
#define TRANSFORM_TRANSLATION(obj_name,frame_no,length,aPosX,aPosY,aPosZ,aDirX,aDirY,aDirZ) \\
class ##obj_name##_trans_##frame_no## \\
{\\
	type		= direct;\\
	source		= %;\\
	selection	= obj_name##_base;\\
	axisPos[]	= {aPosX,aPosY,aPosZ};\\
	axisDir[]	= {-aDirX,-aDirY,aDirZ};\\
	angle		= 0;\\
	axisOffset	= -length;\\
	minValue	= (frame_no-1)/TOTAL_FRAMES;\\
	maxValue	= (frame_no)/TOTAL_FRAMES;\\
};
#define TRANSFORM_ROTATION(obj_name,frame_no,rotAng,aPosX,aPosY,aPosZ,aDirX,aDirY,aDirZ) \\
class ##obj_name##_rot_##frame_no## \\
{\\
	type		= direct;\\
	source		= %;\\
	selection	= obj_name;\\
	axisPos[]	= {aPosX,aPosY,aPosZ};\\
	axisDir[]	= {-aDirX,-aDirY,aDirZ};\\
	angle		= rotAng;\\
	axisOffset	= 0;\\
	minValue	= (frame_no-1)/TOTAL_FRAMES;\\
	maxValue	= (frame_no)/TOTAL_FRAMES;\\
};"
-- Scale of our max rig  
rigScale = 10

-- Attempt to read some default values if model center is present
if(getAppData rootNode frameExporter_ID_scale  != undefined)then(
	rigScale = (getAppData rootNode frameExporter_ID_scale ) as float
)

-- Default model center string
if frameExporter_modelCenter == undefined then
(
	frameExporter_modelCenterString = "Model center: [0,0,0]"
)
frameExporter_source = "reloadMagazine.0"
frameExporter_range = [0.1,1000,rigScale]

-- Main UI
rollout exportFrameDataMainUI "Export Frame Data"
(
	label mainLabel "Frame Exporter" 
	label versionLabel "v0.9.6"
	label authorLabel "Author: Redphoenix and Reyhard"

	-- Model Params group
	group "Model params" 
	(
		spinner scaleFactor "Scale: " range:frameExporter_range type:#float align:#left offset:[0,0] 
		edittext animationSource "Source:" text:frameExporter_source fieldWidth:120 height:18 labelOnTop: true \
		tooltip: "Name of animation source"
		pickbutton pickCenter frameExporter_modelCenterString width:buttonWidth height:buttonHeight offset:[0,10] \
		tooltip: "By default script looks for object called as \"model center\". This object respresents [0,0,0] position of your model. \nRight click on button restart to default."
		pickbutton pickParent "--Parent Object--" width:buttonWidth height:buttonHeight \
		tooltip: "If your bone is attached to something in model.cfg then use this button otherwise model center will be used. \nRight click to undefine."
		pickbutton pickChild "--Child Object--" width:buttonWidth height:buttonHeight \
		tooltip: ""	
	)
	-- Save Params group
	group "Save params" 
	(
		checkbox addHeaderBox "Add animations macros" checked:frameExporter_addHeader
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

	-- Actions
	on scaleFactor changed val do 
	(
		global rigScale = val
		setAppData rootNode frameExporter_ID_scale (val as string)
	)
	on animationSource changed val do
	(
		frameExporter_source = val
		print frameExporter_source as string
		if frameExporter_childObject != undefined then
		(
			setAppData frameExporter_childObject frameExporter_ID_source val
		)
	)
	on pickCenter picked center do
	(
		pickCenter.text = "Model center: " + center.name
		global frameExporter_modelCenter = getNodeByName center.name
	)	
	on pickCenter rightclick do
	(
		pickCenter.text = "Model center: [0,0,0]"
		global frameExporter_modelCenter = undefined
	)	
		
	on pickParent picked parent do
	(
		pickParent.text = "Parent: " + parent.name
		global frameExporter_parentObject = parent
	)
	on pickParent rightclick do
	(
		pickParent.text = "--Parent Object--"
		global frameExporter_parentObject = undefined
	)	
	
	on pickChild picked child do
	(
		pickChild.text = "Child: " + child.name
		global frameExporter_childObject = child
		
		-- Grab local data from children
		if(getAppData frameExporter_childObject frameExporter_ID_source  != undefined)then(
			frameExporter_source = (getAppData frameExporter_childObject frameExporter_ID_source )
			animationSource.text = frameExporter_source
		)
		if(getAppData frameExporter_childObject frameExporter_ID_savePath  != undefined)then(
			frameExporter_savePath = (getAppData frameExporter_childObject frameExporter_ID_savePath )
			savePathEdit.text = frameExporter_savePath
		)
	)

	on addHeaderBox changed val do 
	(
		frameExporter_addHeader = val
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
			frameExporter_savePath = savePath
			if frameExporter_childObject != undefined then
			(
				setAppData frameExporter_childObject frameExporter_ID_savePath savePath
			)
		)
	)

	on exportTxTFile pressed do
	(
		-- Input validation
		if frameExporter_modelCenter == undefined then
		(
			-- Create dummy center
			frameExporter_modelCenter = dummy boxsize: [0.01,0.01,0.01] transform: (Matrix3 [10,0,0] [0,0,10] [0,-10,0] [0,0,0])
			frameExporter_dummy = true
		)
		if frameExporter_parentObject == undefined then
		(
			frameExporter_parentObject = frameExporter_modelCenter
		)
		if frameExporter_parentObject == undefined then
		(
			messagebox "Please select a parent" title:"No Parent"
			return false
		)
		if frameExporter_childObject == undefined then
		(
			messagebox "Please select child" title:"No Child"
			return false
		)
		if savePath == "" then
		(
			frameExporter_savePath = getSaveFilename caption:"Save Frame Data to..."  types:"Text File(*.txt)|*.txt|All|*.*|"
		)
		-- Variables
		weaponRealtivePosition = [0,0,0]
		childStr = (frameExporter_childObject.name) as string
		oldTransform = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform))
		frameDataTextStream = stringStream ""

		if frameExporter_addHeader then
		(
			format frameExporter_header ((animationRange.end.frame as integer) as string) frameExporter_source frameExporter_source to:frameDataTextStream
		)
		start = true

		for t = animationRange.start to animationRange.end do
		(
			animate on
			(
				at time t
				(
					-- Get start position. It will serve as our reference position
					if start then
					(	
						oldTransform = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform))
						weaponRealtivePosition = (frameExporter_childObject.transform * (inverse frameExporter_modelCenter.transform)).pos
						weaponRealtivePosition = divide_vector weaponRealtivePosition rigScale
						start = false
					)

					frameName = ((t.frame as integer) - 1) as string;
					currentTransform = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform))

					-- Get translation
					-- If there is change frame by frame then list animation in output file
					relativeTransformation = (currentTransform * (inverse oldTransform)).pos
					-- Get vector length, round it and output change if size of it bigger than 0
					relativeLength = (length (relativeTransformation))  / rigScale
					relativeLength = (round_to relativeLength 5) as float 
					if relativeLength > 0.001 then
					(
						vectorDirection = currentTransform.pos - oldTransform.pos
						-- Disabled. Matrix operations are stacked and this method needs improvment - as a workaround translation is stored in separate bone
						-- weaponRealtivePosition = weaponRealtivePosition + vectorDirection

						-- Adjust size of vector to our scale
						relativePosition = divide_vector currentTransform.pos rigScale
						vectorPosition = round_vector_to relativePosition 5
						vectorDirection = round_vector_to vectorDirection 5
						vectorPosition = remove_brackets (vectorPosition as string)
						vectorDirection = remove_brackets (vectorDirection as string) 
						-- Compose string and add it to string stream
						format "\n TRANSFORM_TRANSLATION(%,%,%,%,%)" (childStr) (frameName) (relativeLength as string) (vectorPosition) (vectorDirection)  to:frameDataTextStream
					)

					-- Get rotations and save them as macro
					-- Do comparsion between current and previous (from frame before) then output result as angle axis which Arma is using for everything
					relativeRotation = ( (currentTransform * (inverse oldTransform)).rotation) as angleAxis
					roundedAngle = round_to relativeRotation.angle 4
					if roundedAngle > 0 then
					(
						relativeRotationVec = round_vector_to relativeRotation.axis 3
						-- We need to scale up vector before transforming by matrix
						relativeRotationVec =  divide_vector (relativeRotationVec) 0.1
						-- Transform vector by current local transformation matrix. (aka converting to transform space)
						relativeRotationVec = divide_vector (relativeRotationVec *  (matrix3 currentTransform.row1 currentTransform.row2 currentTransform.row3 [0,0,0])) 10
						relativeRotationVec = round_vector_to relativeRotationVec 3
						directionVectorStr = remove_brackets (relativeRotationVec as string)
						
						vectorPosition = round_vector_to weaponRealtivePosition 4 
						vectorPosition = vectorPosition as string
						vectorPosition = remove_brackets vectorPosition  
						-- Compose string and add it to string stream
						format "\n TRANSFORM_ROTATION(%,%,%,%,%)" (childStr) (frameName) (roundedAngle as string) (vectorPosition) (directionVectorStr) to:frameDataTextStream
					)
					
					oldTransform = currentTransform
				)
			)
		)
		--print frameDataTextStream
		-- Save string to file
		frameDataTextFile = createfile (frameExporter_savePath)
		format "%" (frameDataTextStream as string) to:frameDataTextFile			
		close FrameDataTextFile
		free FrameDataTextFile
		-- Remove dummy model center after calculations are done
		if frameExporter_dummy then
		(
			if frameExporter_parentObject == frameExporter_modelCenter then  frameExporter_parentObject = undefined
			delete frameExporter_modelCenter
			frameExporter_modelCenter = undefined
			frameExporter_dummy = false
		)
	)
)

exportFrameDataMainUIFloater = newrolloutfloater "Export Frame Data" UIWidth UIHeight
addRollout exportFrameDataMainUI exportFrameDataMainUIFloater border:false
