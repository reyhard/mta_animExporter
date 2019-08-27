@echo off
TITLE FBX to RTM Converter

SETLOCAL ENABLEEXTENSIONS

for /F "Tokens=2* skip=2" %%A In ('REG QUERY "HKCU\SOFTWARE\bohemia interactive\arma 3 tools" /v "path" 2^>nul') do (set _TOOLPATH=%%B)

if "%_TOOLPATH%" == "" (
	echo Arma 3 Tools can't be found
)

set Fbx2RtmPath=%_TOOLPATH%\FBXToRTM

for %%i in (%*) do (
    echo %%i
    "%Fbx2RtmPath%\Fbx2Rtm.exe" -cfg "%Fbx2RtmPath%\modelBoxKiory.xml" -skeleton ManSkeleton -bindpose "%Fbx2RtmPath%\bindPoseMan_New.fbx" -log export.log -step Hips -fps 30 -scale 0.0100 %%i
)
exit /B
