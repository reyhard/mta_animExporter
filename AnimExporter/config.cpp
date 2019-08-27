class CfgPatches
{
	class AnimExporter_Demo
	{
		requiredAddons[]	= {A3_Data_F_Enoch_Loadorder};
		requiredVersion		= 0.1;
		units[]				= {AnimExpoter_Demo_Plane};
		weapons[]			= {AnimExporter_Demo_Weapon};
		version				= 1.0;
	};
};

#include "cfgMoves.hpp"

class CfgVehicles
{
	class House_F;
	class AnimExpoter_Demo_Plane: House_F
	{
		scope			= 2;
		scopeCurator	= 2;
		model			= "AnimExporter\plane_example";
		displayName		= "Anim Expoter Demo Plane";
		class AnimationSources
		{
			class randUserSource {source = user;initPhase = 0;animPeriod = 6;};
		};
		class EventHandlers
		{
			init = "(_this # 0) spawn {while{alive _this}do{_this animateSource ['randUserSource',abs((_this animationSourcePhase 'randUserSource') - 1)];sleep 6.3}};";
		};
	};
};

class CfgWeapons
{
	class arifle_MX_GL_F;
	class AnimExporter_Demo_Weapon: arifle_MX_GL_F
	{
		model			= "AnimExporter\weapon_example.p3d";
		displayName		= "Anim Expoter Demo Weapon";
		reloadAction	= "AnimExporter_GestureReload_Demo";
		baseWeapon		= "AnimExporter_Demo_Weapon";
		selectionFireAnim = "muzzleFlash";
	};
};