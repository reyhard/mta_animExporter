ClearListener()

global exportFrameDataMainUIFloater
try(removeRollout exportFrameDataMainUIFloater)catch()

-- Misc Variables
UIHeight = 250
UIWidth = 180

buttonHeight = 50
buttonWidth = 150

-- Scale of our max rig  
rigScale = 10

frameExporter_parentObject = undefined
frameExporter_childObject = undefined
frameExporter_weaponCenter = (getNodeByName "weapon center") 

--
rollout exportFrameDataMainUI "Export Frame Data"
(
	label mainLabel "Frame Exporter" 
	label versionLabel "v0.8.0"
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
	fn writeAngleOutput angleDifference childStr frameName weaponRealtivePosition FrameDataTextFile vectorDirStr vectorNameStr =
	(
		format "\n %" ("TRANSFORM_ROTATION("+ childStr  + ","+ frameName ) to:FrameDataTextFile

		format ",%" (angleDifference as string) to:FrameDataTextFile

		local vectorPosition = round_vector_to weaponRealtivePosition 4 
		vectorPosition = vectorPosition as string
		vectorPosition = remove_brackets vectorPosition  
		format ",%" (vectorPosition) to:FrameDataTextFile
		format ",%,%)" (vectorDirStr) vectorNameStr to:FrameDataTextFile
		true
	)
	on exportTxTFile pressed do
	(
		if frameExporter_parentObject != undefined then
		(
			if frameExporter_childObject != undefined then
			(
				-- savePath = getSaveFilename caption:"Save Frame Data to..."  types:"Text File(*.txt)|*.txt|All|*.*|"
				-- Save it to test file to speed up debuging
				--savePath = "H:\\Projekty\\Arma3\\rhsgref\\addons\\rhsgref_weapons2\m79\\exportedAnims.hpp"
				savePath = "H:\\Projekty\\Arma3\\rhsgref\\addons\\rhsgref_weapons\\izh_18\\exportedAnims.hpp"
				-- savePath = "H:\\Projekty\\Arma3\\rhsgref\\addons\\rhsgref_weapons2\\m1garand\\exportedAnims.hpp"
				FrameDataTextFile = createfile (savePath)
				startPosition = [0,0,0]
				weaponRealtivePosition = [0,0,0]
				lastRotX = 0
				lastRotY = 0
				lastRotZ = 0
				childStr = frameExporter_childObject.name 
				childStr = childStr as string
				start = true
				oldTransform = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform))
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
								startPosition = (frameExporter_childObject.transform * (inverse frameExporter_parentObject.transform)).pos
								-- Adjust size of vector to our scale
								startPosition = divide_vector startPosition rigScale
								weaponRealtivePosition = (frameExporter_childObject.transform * (inverse frameExporter_weaponCenter.transform)).pos
								weaponRealtivePosition = divide_vector weaponRealtivePosition rigScale
								start = false
							)
							if frameExporter_parentObject != undefined then
							(
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
									-- Using macro to generate it
									format "\n %" ("TRANSFORM_TRANSLATION("+ childStr + ","+ frameName) to:FrameDataTextFile
									
									vectorDirection = relativePosition - startPosition
									-- weaponRealtivePosition = weaponRealtivePosition + vectorDirection
									vectorDirection = round_vector_to vectorDirection 5
									vectorDirection = vectorDirection as string

									startPosition = relativePosition
									format ",%" (relativeLength as string) to:FrameDataTextFile

									vectorPosition = round_vector_to relativePosition 5
									vectorPosition = vectorPosition as string
									vectorPosition = remove_brackets vectorPosition 
									format ",%" (vectorPosition) to:FrameDataTextFile

									vectorDirection = remove_brackets vectorDirection 
									format ",%)" (vectorDirection) to:FrameDataTextFile
								)

								-- Get rotations and save them as macro
								relativeRotation = ((currentTransform * (inverse oldTransform)).rotation) as angleAxis
								relativeRotationVec = round_vector_to relativeRotation.axis 4
								--relativeRotationVec = relativeRotationVec * frameExporter_childObject.dir
								-- We need local  
								print (frameExporter_childObject.dir ) as string
								roundedAngle = round_to relativeRotation.angle 4
								if roundedAngle > 0.1 then
								(
									directionVectorStr = round_vector_to relativeRotation.axis 4
									directionVectorStr = remove_brackets (directionVectorStr as string)
									output_string = writeAngleOutput roundedAngle childStr frameName weaponRealtivePosition FrameDataTextFile directionVectorStr "x"
								)
								/*if rotX != lastRotX then
								(
									angleDifference = round_to (rotX - lastRotX) 4
									lastRotX = rotX
									directionVectorStr = round_vector_to directionVector[1] 4
									directionVectorStr = remove_brackets (directionVectorStr as string)
									output_string = writeAngleOutput angleDifference childStr frameName weaponRealtivePosition FrameDataTextFile directionVectorStr "x"
								)
								if rotY != lastRotY then
								(
									angleDifference = round_to (rotY - lastRotY) 4
									lastRotY = rotY
									directionVectorStr = round_vector_to directionVector[2] 4
									directionVectorStr = remove_brackets (directionVectorStr as string)
									output_string = writeAngleOutput angleDifference childStr frameName weaponRealtivePosition FrameDataTextFile directionVectorStr "y"
								)
								if rotZ != lastRotZ then
								( 
									angleDifference = round_to (rotZ - lastRotZ) 4
									lastRotZ = rotZ
									directionVectorStr = round_vector_to directionVector[3] 4
									directionVectorStr = remove_brackets (directionVectorStr as string)
									output_string = writeAngleOutput angleDifference childStr frameName weaponRealtivePosition FrameDataTextFile directionVectorStr "z"
								)*/
								
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
