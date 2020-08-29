ClearListener()

global exportFrameDataMainUIFloater
if exportFrameDataMainUIFloater!=undefined then (
    closeRolloutFloater exportFrameDataMainUIFloater
)

-- Misc Variables
UIHeight = 305
UIWidth = 200

buttonHeight = 50
buttonWidth = 170

animExporter_savePath = ""
animExporter_ID_startFrame = 0
animExporter_ID_endFrame = 1
animExporter_ID_animationName = 2
animExporter_ID_presetPath = 3
animExporter_ID_savePath = 4
-- Scale of our max rig  
animExporter_startFrame = 0
animExporter_endFrame = 1
animExporter_animationName = ""

-- Attempt to read some default values
if(getAppData rootNode animExporter_ID_startFrame  != undefined)then(
	animExporter_startFrame = (getAppData rootNode animExporter_ID_startFrame ) as integer
)
if(getAppData rootNode animExporter_ID_endFrame  != undefined)then(
	animExporter_endFrame = (getAppData rootNode animExporter_ID_endFrame ) as integer
)
if(getAppData rootNode animExporter_ID_animationName   != undefined)then(
	animExporter_animationName = (getAppData rootNode animExporter_ID_animationName ) as string
)
if(getAppData rootNode animExporter_ID_savePath   != undefined)then(
	animExporter_savePath = (getAppData rootNode animExporter_ID_savePath ) as string
)
animExporter_startFrameRange = [1,1000,animExporter_startFrame]
animExporter_endFrameRange = [1,1000,animExporter_endFrame]

-- Main UI
rollout exportFrameDataMainUI "Animation Data"
(
	label mainLabel "Animation Exporter" 
	label versionLabel "v0.1"
	label authorLabel "Author: Reyhard"

	-- Model Params group
	group "Animation params" 
	(
		--spinner animationStart "Animation start: " range:animExporter_startFrameRange type:#integer align:#right offset:[0,0] 
		--spinner animationEnd "Animation end: " range:animExporter_endFrameRange type:#integer align:#right offset:[0,0] 
		edittext animationName "Animation name:" text:animExporter_animationName fieldWidth:160 height:18 labelOnTop: true \
		tooltip: "Name of animation source"
	)
	-- Save Params group
	group "Save params" 
	(
		--edittext presetPathEdit "Preset path:" text:animExporter_savePath fieldWidth:160 height:18 labelOnTop: true readOnly: false
		--button pickPresetPath "Pick preset path" width:buttonWidth height:buttonHeight
		edittext savePathEdit "Save path:" text:animExporter_savePath fieldWidth:160 height:18 labelOnTop: true readOnly: false
		button pickSavePath "Pick save path" width:buttonWidth height:buttonHeight
		button exportTxTFile "Export animation" width:buttonWidth height:buttonHeight
	)
	
	-- Functions

	-- Actions
	on animationStart changed val do 
	(
		global animExporter_startFrame = val
		setAppData rootNode animExporter_ID_startFrame (val as string)
	)
	on animationEnd changed val do 
	(
		global animExporter_endFrame = val
		setAppData rootNode animExporter_ID_endFrame (val as string)
	)
	on animationName changed val do
	(
		global animExporter_animationName = val
		setAppData rootNode animExporter_ID_animationName (val as string)
	)

	on savePathEdit changed val do
	(
		animExporter_savePath = val
		setAppData rootNode animExporter_ID_savePath (val as string)
	)
	on pickSavePath pressed do
	(
		local savePath = getSavePath  caption:"Set folder where animation will be stored"
		if savePath != undefined then
		(
			savePathEdit.text = savePath
			animExporter_savePath = savePath
			setAppData rootNode animExporter_ID_savePath savePath
		)
	)

	on exportTxTFile pressed do
	(
		FBXExporterSetParam "FileVersion" "FBX200900"
		FBXExporterSetParam "Animation" true
		FBXExporterSetParam "BakeAnimation" true
		--FBXExporterSetParam "BakeFrameStart" animExporter_startFrame
		--FBXExporterSetParam "BakeFrameEnd" animExporter_endFrame
		FBXExporterSetParam "BakeResampleAnimation" false
		FBXExporterSetParam "ShowWarnings" false
		completeFilePath = (animExporter_savePath + "/" + animExporter_animationName)
		exportFile completeFilePath #noPrompt using:FBXEXP

		-- Script assumes that toRTM batch file is located in same location as animation
		shellPAth = animExporter_savePath + "/" + "toRtm.bat"
		completeFilePathFBX = completeFilePath + ".fbx"
		ShellLaunch shellPAth completeFilePathFBX
	)
)

exportFrameDataMainUIFloater = newrolloutfloater "Export Frame Data" UIWidth UIHeight
addRollout exportFrameDataMainUI exportFrameDataMainUIFloater border:false
