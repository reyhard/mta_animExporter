# mta_animExporter
Export weapon animations to Arma 3 model.cfg

			#define TOTAL_FRAMES 110
			#define TRANSFORM(obj_name,frame_no,length,aPosX,aPosY,aPosZ,aDirX,aDirY,aDirZ)\
			class ##obj_name##_trans_##frame_no##\
			{\
				type		= direct;\
				source		= reloadMagazine.0;\
				selection	= obj_name;\
				axisPos[]	= {aPosX,aPosY,aPosZ};\
				axisDir[]	= {aDirX,aDirY,aDirZ};\
				angle		= 0;\
				axisOffset	= length;\
				minValue	= frame_no-1/TOTAL_FRAMES;\
				maxValue	= frame_no/TOTAL_FRAMES;\
			};
