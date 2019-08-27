class CfgMovesBasic
{
	class Default;
	class DefaultDie;

	class ManActions
	{
		// Gestures
		AnimExporter_GestureReload_Demo			= "AnimExporter_GestureReload_Demo";
	};

	class Actions
	{
		class NoActions : ManActions
		{
			AnimExporter_GestureReload_Demo[]		= { "AnimExporter_GestureReload_Demo", "Gesture" };
		};
		class RifleBaseStandActions;
		class RifleProneActions: RifleBaseStandActions
		{
			AnimExporter_GestureReload_Demo[]		= { "AnimExporter_GestureReload_Demo_Prone", "Gesture" };
		};
		class RifleAdjustProneBaseActions;
		class RifleAdjustRProneActions: RifleAdjustProneBaseActions
		{
			AnimExporter_GestureReload_Demo[]		= { "AnimExporter_GestureReload_Demo_Context", "Gesture" };
		};
		class RifleAdjustLProneActions: RifleAdjustProneBaseActions
		{
			AnimExporter_GestureReload_Demo[]		= { "AnimExporter_GestureReload_Demo_Context", "Gesture" };
		};
		class RifleAdjustFProneActions: RifleAdjustProneBaseActions
		{
			AnimExporter_GestureReload_Demo[]		= { "AnimExporter_GestureReload_Demo_Prone", "Gesture" };
		};
	};
};
#define ANIMATION_DURATION_S(duration)  __EVAL(1/duration)
class CfgGesturesMale
{
	class Default;
	class States
	{
		class GestureReloadBase;
		class AnimExporter_GestureReload_Demo : GestureReloadBase
		{
			file				= "\AnimExporter\weapon_anim_example.rtm";
			speed				= ANIMATION_DURATION_S(3.7);

			leftHandIKCurve[] =
			{
				0, 1,
				0.05, 0.0,
				0.95, 0,
				0.99,1
			};
			rightHandIKCurve[] =
			{
				0.0, 1,
				0.05,0.0,
				0.95, 0.0,
				0.99,1
			};
			leftHandIKBeg		= true;
			leftHandIKEnd		= true;
			rightHandIKBeg		= true;
			rightHandIKEnd		= true;
		};
		class AnimExporter_GestureReload_Demo_prone : AnimExporter_GestureReload_Demo
		{
			file				= "\AnimExporter\weapon_anim_example.rtm";
			mask				= "handsWeapon";
		};
		class AnimExporter_GestureReload_Demo_Context : AnimExporter_GestureReload_Demo_prone
		{
			mask = "handsWeapon_context";
		};
	};
};