
#define TOTAL_FRAMES (160/1)
#define FRAME(fr) (fr/TOTAL_FRAMES)
#define TRANSFORM_TRANSLATION(obj_name,frame_no,length,aPosX,aPosY,aPosZ,aDirX,aDirY,aDirZ) \
class ##obj_name##_trans_##frame_no## \
{\
	type		= direct;\
	source		= randUserSource;\
	selection	= obj_name##_base;\
	axisPos[]	= {aPosX,aPosY,aPosZ};\
	axisDir[]	= {-aDirX,-aDirY,aDirZ};\
	angle		= 0;\
	axisOffset	= -length;\
	minValue	= (frame_no-1)/TOTAL_FRAMES;\
	maxValue	= (frame_no)/TOTAL_FRAMES;\
};
#define TRANSFORM_ROTATION(obj_name,frame_no,rotAng,aPosX,aPosY,aPosZ,aDirX,aDirY,aDirZ) \
class ##obj_name##_rot_##frame_no## \
{\
	type		= direct;\
	source		= randUserSource;\
	selection	= obj_name;\
	axisPos[]	= {aPosX,aPosY,aPosZ};\
	axisDir[]	= {-aDirX,-aDirY,aDirZ};\
	angle		= rotAng;\
	axisOffset	= 0;\
	minValue	= (frame_no-1)/TOTAL_FRAMES;\
	maxValue	= (frame_no)/TOTAL_FRAMES;\
};
 TRANSFORM_TRANSLATION(objPlane,0,0.07253,3.82947,1.77571,-0.02733,0.00606,0,0.07228)
 TRANSFORM_ROTATION(objPlane,0,0.1399,3.82341,1.77571,-0.09961,0.43034,0.79218,-0.43274)
 TRANSFORM_TRANSLATION(objPlane,1,0.20765,3.8466,1.77571,0.17961,0.01713,0,0.20694)
 TRANSFORM_ROTATION(objPlane,1,0.4119,3.82341,1.77571,-0.09961,0.42408,0.79636,-0.43124)
 TRANSFORM_TRANSLATION(objPlane,2,0.32784,3.87321,1.77571,0.50637,0.02661,0,0.32676)
 TRANSFORM_ROTATION(objPlane,2,0.6727,3.82341,1.77571,-0.09961,0.41801,0.80131,-0.42798)
 TRANSFORM_TRANSLATION(objPlane,3,0.43311,3.90773,1.77571,0.9381,0.03452,0,0.43173)
 TRANSFORM_ROTATION(objPlane,3,0.9228,3.82341,1.77571,-0.09961,0.41266,0.80665,-0.42311)
 TRANSFORM_TRANSLATION(objPlane,4,0.52346,3.94857,1.77571,1.45996,0.04084,0,0.52186)
 TRANSFORM_ROTATION(objPlane,4,1.1625,3.82341,1.77571,-0.09961,0.40799,0.81231,-0.41678)
 TRANSFORM_TRANSLATION(objPlane,5,0.59888,3.99415,1.77571,2.05711,0.04558,0,0.59714)
 TRANSFORM_ROTATION(objPlane,5,1.3921,3.82341,1.77571,-0.09961,0.40391,0.8182,-0.40914)
 TRANSFORM_TRANSLATION(objPlane,6,0.65939,4.0429,1.77571,2.71469,0.04875,0,0.65758)
 TRANSFORM_ROTATION(objPlane,6,1.6118,3.82341,1.77571,-0.09961,0.4003,0.82429,-0.40037)
 TRANSFORM_TRANSLATION(objPlane,7,0.70498,4.09323,1.77571,3.41787,0.05033,0,0.70318)
 TRANSFORM_ROTATION(objPlane,7,1.8216,3.82341,1.77571,-0.09961,0.39704,0.83053,-0.39061)
 TRANSFORM_TRANSLATION(objPlane,8,0.73565,4.14355,1.77571,4.15179,0.05033,0,0.73393)
 TRANSFORM_ROTATION(objPlane,8,2.0217,3.82341,1.77571,-0.09961,0.39397,0.83687,-0.38004)
 TRANSFORM_TRANSLATION(objPlane,9,0.75142,4.1923,1.77571,4.90162,0.04875,0,0.74983)
 TRANSFORM_ROTATION(objPlane,9,2.2118,3.82341,1.77571,-0.09961,0.391,0.84327,-0.36882)
 TRANSFORM_TRANSLATION(objPlane,10,0.75228,4.23789,1.77571,5.65252,0.04558,0,0.75089)
 TRANSFORM_ROTATION(objPlane,10,2.3919,3.82341,1.77571,-0.09961,0.388,0.84965,-0.35715)
 TRANSFORM_TRANSLATION(objPlane,11,0.73824,4.27873,1.77571,6.38963,0.04084,0,0.73711)
 TRANSFORM_ROTATION(objPlane,11,2.5617,3.82341,1.77571,-0.09961,0.38487,0.856,-0.34518)
 TRANSFORM_TRANSLATION(objPlane,12,0.70932,4.31325,1.77571,7.09811,0.03452,0,0.70848)
 TRANSFORM_ROTATION(objPlane,12,2.721,3.82341,1.77571,-0.09961,0.38151,0.86226,-0.33312)
 TRANSFORM_TRANSLATION(objPlane,13,0.66554,4.33986,1.77571,7.76312,0.02661,0,0.66501)
 TRANSFORM_ROTATION(objPlane,13,2.8695,3.82341,1.77571,-0.09961,0.37785,0.86837,-0.32117)
 TRANSFORM_TRANSLATION(objPlane,14,0.60693,4.35699,1.77571,8.36981,0.01713,0,0.60669)
 TRANSFORM_ROTATION(objPlane,14,3.0069,3.82341,1.77571,-0.09961,0.37386,0.87431,-0.30952)
 TRANSFORM_TRANSLATION(objPlane,15,0.53356,4.36305,1.77571,8.90334,0.00606,0,0.53353)
 TRANSFORM_ROTATION(objPlane,15,3.1328,3.82341,1.77571,-0.09961,0.3695,0.88002,-0.29838)
 TRANSFORM_TRANSLATION(objPlane,16,0.51031,4.2703,1.77571,9.40515,-0.09274,0,0.50181)
 TRANSFORM_ROTATION(objPlane,16,3.2467,3.82341,1.77571,-0.09961,0.36478,0.88545,-0.28796)
 TRANSFORM_TRANSLATION(objPlane,17,0.56888,4.01734,1.77571,9.91469,-0.25296,0,0.50954)
 TRANSFORM_ROTATION(objPlane,17,3.3485,3.82341,1.77571,-0.09961,0.35972,0.89054,-0.27846)
 TRANSFORM_TRANSLATION(objPlane,18,0.62473,3.64206,1.77571,10.4141,-0.37528,0,0.49945)
 TRANSFORM_ROTATION(objPlane,18,3.4375,3.82341,1.77571,-0.09961,0.35438,0.89525,-0.27009)
 TRANSFORM_TRANSLATION(objPlane,19,0.65854,3.18235,1.77571,10.8857,-0.45971,0,0.47152)
 TRANSFORM_ROTATION(objPlane,19,3.5135,3.82341,1.77571,-0.09961,0.34884,0.8995,-0.26307)
 TRANSFORM_TRANSLATION(objPlane,20,0.66148,2.6761,1.77571,11.3114,-0.50624,0,0.42577)
 TRANSFORM_ROTATION(objPlane,20,3.5761,3.82341,1.77571,-0.09961,0.34322,0.90325,-0.25758)
 TRANSFORM_TRANSLATION(objPlane,21,0.62951,2.16122,1.77571,11.6736,-0.51488,0,0.36219)
 TRANSFORM_ROTATION(objPlane,21,3.6249,3.82341,1.77571,-0.09961,0.33765,0.9064,-0.25383)
 TRANSFORM_TRANSLATION(objPlane,22,0.56095,1.67561,1.77571,11.9544,-0.48562,0,0.28078)
 TRANSFORM_ROTATION(objPlane,22,3.6598,3.82341,1.77571,-0.09961,0.33229,0.90888,-0.25202)
 TRANSFORM_TRANSLATION(objPlane,23,0.45614,1.25715,1.77571,12.1359,-0.41846,0,0.18154)
 TRANSFORM_ROTATION(objPlane,23,3.6804,3.82341,1.77571,-0.09961,0.32734,0.91059,-0.25234)
 TRANSFORM_TRANSLATION(objPlane,24,0.31997,0.94374,1.77571,12.2004,-0.3134,0,0.06448)
 TRANSFORM_ROTATION(objPlane,24,3.6866,3.82341,1.77571,-0.09961,0.32301,0.9114,-0.25497)
 TRANSFORM_TRANSLATION(objPlane,25,0.24604,0.69996,1.79083,12.1708,-0.24379,0.01512,-0.02957)
 TRANSFORM_ROTATION(objPlane,25,4.9471,3.82341,1.77571,-0.09961,0.31323,0.91421,-0.2571)
 TRANSFORM_TRANSLATION(objPlane,26,0.25399,0.4647,1.83472,12.0858,-0.23526,0.04389,-0.08508)
 TRANSFORM_ROTATION(objPlane,26,7.0502,3.82341,1.77571,-0.09961,0.32267,0.91606,-0.23815)
 TRANSFORM_TRANSLATION(objPlane,27,0.27368,0.2374,1.90519,11.9506,-0.2273,0.07047,-0.13516)
 TRANSFORM_ROTATION(objPlane,27,8.5188,3.82341,1.77571,-0.09961,0.34598,0.91649,-0.20087)
 TRANSFORM_TRANSLATION(objPlane,28,0.29948,0.01748,2.00005,11.7708,-0.21992,0.09486,-0.1798)
 TRANSFORM_ROTATION(objPlane,28,9.357,3.82341,1.77571,-0.09961,0.37083,0.91646,-0.15031)
 TRANSFORM_TRANSLATION(objPlane,29,0.32723,-0.19563,2.1171,11.5518,-0.21311,0.11705,-0.219)
 TRANSFORM_ROTATION(objPlane,29,9.573,3.82341,1.77571,-0.09961,0.39013,0.91627,-0.09083)
 TRANSFORM_TRANSLATION(objPlane,30,0.35422,-0.4025,2.25415,11.299,-0.20687,0.13705,-0.25277)
 TRANSFORM_ROTATION(objPlane,30,9.1762,3.82341,1.77571,-0.09961,0.40011,0.91604,-0.02795)
 TRANSFORM_TRANSLATION(objPlane,31,0.37879,-0.60371,2.409,11.0179,-0.20121,0.15486,-0.2811)
 TRANSFORM_ROTATION(objPlane,31,8.1754,3.82341,1.77571,-0.09961,0.40027,0.91583,0.03205)
 TRANSFORM_TRANSLATION(objPlane,32,0.39992,-0.79983,2.57947,10.714,-0.19612,0.17047,-0.30399)
 TRANSFORM_ROTATION(objPlane,32,6.5767,3.82341,1.77571,-0.09961,0.39319,0.91568,0.08321)
 TRANSFORM_TRANSLATION(objPlane,33,0.41696,-0.99143,2.76336,10.3925,-0.19161,0.18389,-0.32145)
 TRANSFORM_ROTATION(objPlane,33,4.3832,3.82341,1.77571,-0.09961,0.38358,0.9156,0.12064)
 TRANSFORM_TRANSLATION(objPlane,34,0.42952,-1.1791,2.95847,10.059,-0.18767,0.19511,-0.33347)
 TRANSFORM_ROTATION(objPlane,34,1.5941,3.82341,1.77571,-0.09961,0.3768,0.91557,0.14055)
 TRANSFORM_TRANSLATION(objPlane,35,0.43735,-1.3634,3.16262,9.71898,-0.1843,0.20415,-0.34005)
 TRANSFORM_ROTATION(objPlane,35,1.7297,3.82341,1.77571,-0.09961,-0.88669,-0.04684,-0.45999)
 TRANSFORM_TRANSLATION(objPlane,36,0.44031,-1.5449,3.37361,9.37779,-0.18151,0.21099,-0.3412)
 TRANSFORM_ROTATION(objPlane,36,4.782,3.82341,1.77571,-0.09961,-0.88801,-0.04689,-0.45742)
 TRANSFORM_TRANSLATION(objPlane,37,0.43834,-1.72419,3.58924,9.04089,-0.17929,0.21563,-0.3369)
 TRANSFORM_ROTATION(objPlane,37,7.2239,3.82341,1.77571,-0.09961,-0.89042,-0.04705,-0.4527)
 TRANSFORM_TRANSLATION(objPlane,38,0.43146,-1.90183,3.80733,8.71371,-0.17764,0.21809,-0.32718)
 TRANSFORM_ROTATION(objPlane,38,9.0555,3.82341,1.77571,-0.09961,-0.89363,-0.04729,-0.44629)
 TRANSFORM_TRANSLATION(objPlane,39,0.41977,-2.0784,4.02568,8.4017,-0.17657,0.21835,-0.31201)
 TRANSFORM_ROTATION(objPlane,39,10.2766,3.82341,1.77571,-0.09961,-0.89736,-0.04764,-0.43871)
 TRANSFORM_TRANSLATION(objPlane,40,0.40343,-2.25447,4.24209,8.11029,-0.17607,0.21641,-0.29141)
 TRANSFORM_ROTATION(objPlane,40,10.8874,3.82341,1.77571,-0.09961,-0.90134,-0.04806,-0.43045)
 TRANSFORM_TRANSLATION(objPlane,41,0.38277,-2.43061,4.45438,7.84492,-0.17615,0.21229,-0.26537)
 TRANSFORM_ROTATION(objPlane,41,10.8876,3.82341,1.77571,-0.09961,-0.9053,-0.04854,-0.42198)
 TRANSFORM_TRANSLATION(objPlane,42,0.35831,-2.60741,4.66034,7.61102,-0.1768,0.20597,-0.2339)
 TRANSFORM_ROTATION(objPlane,42,10.2773,3.82341,1.77571,-0.09961,-0.90905,-0.04903,-0.41379)
 TRANSFORM_TRANSLATION(objPlane,43,0.33088,-2.78543,4.8578,7.41403,-0.17802,0.19745,-0.19699)
 TRANSFORM_ROTATION(objPlane,43,9.0565,3.82341,1.77571,-0.09961,-0.91238,-0.04948,-0.40636)
 TRANSFORM_TRANSLATION(objPlane,44,0.30186,-2.96525,5.04454,7.2594,-0.17982,0.18675,-0.15464)
 TRANSFORM_ROTATION(objPlane,44,7.2249,3.82341,1.77571,-0.09961,-0.9151,-0.04985,-0.40013)
 TRANSFORM_TRANSLATION(objPlane,45,0.27356,-3.14744,5.21839,7.15254,-0.18219,0.17385,-0.10685)
 TRANSFORM_ROTATION(objPlane,45,4.7828,3.82341,1.77571,-0.09961,-0.91707,-0.05013,-0.39555)
 TRANSFORM_TRANSLATION(objPlane,46,0.24971,-3.33257,5.37714,7.09891,-0.18513,0.15875,-0.05363)
 TRANSFORM_ROTATION(objPlane,46,1.73,3.82341,1.77571,-0.09961,-0.91813,-0.05027,-0.39307)
 TRANSFORM_TRANSLATION(objPlane,47,0.23444,-3.50789,5.53157,7.07948,-0.17532,0.15443,-0.01943)
 TRANSFORM_ROTATION(objPlane,47,1.5552,3.82341,1.77571,-0.09961,0.93201,0.14855,0.33057)
 TRANSFORM_TRANSLATION(objPlane,48,0.2229,-3.66531,5.68906,7.0695,-0.15742,0.15748,-0.00998)
 TRANSFORM_ROTATION(objPlane,48,4.1853,3.82341,1.77571,-0.09961,0.93098,0.1483,0.33357)
 TRANSFORM_TRANSLATION(objPlane,49,0.21248,-3.81245,5.84231,7.06583,-0.14714,0.15325,-0.00368)
 TRANSFORM_ROTATION(objPlane,49,6.0938,3.82341,1.77571,-0.09961,0.92907,0.14644,0.3397)
 TRANSFORM_TRANSLATION(objPlane,50,0.20238,-3.95691,5.98404,7.0653,-0.14446,0.14173,-0.00052)
 TRANSFORM_ROTATION(objPlane,50,7.2805,3.82341,1.77571,-0.09961,0.92602,0.1439,0.34897)
 TRANSFORM_TRANSLATION(objPlane,51,0.19346,-4.10631,6.10695,7.06478,-0.1494,0.12292,-0.00052)
 TRANSFORM_ROTATION(objPlane,51,7.7468,3.82341,1.77571,-0.09961,0.92153,0.14241,0.36125)
 TRANSFORM_TRANSLATION(objPlane,52,0.18871,-4.26825,6.20378,7.0611,-0.16194,0.09682,-0.00368)
 TRANSFORM_ROTATION(objPlane,52,7.4955,3.82341,1.77571,-0.09961,0.91524,0.14491,0.37594)
 TRANSFORM_TRANSLATION(objPlane,53,0.19308,-4.45033,6.26721,7.05112,-0.18209,0.06344,-0.00998)
 TRANSFORM_ROTATION(objPlane,53,6.5316,3.82341,1.77571,-0.09961,0.90655,0.15718,0.39173)
 TRANSFORM_TRANSLATION(objPlane,54,0.21197,-4.66017,6.28998,7.03169,-0.20984,0.02277,-0.01943)
 TRANSFORM_ROTATION(objPlane,54,4.8635,3.82341,1.77571,-0.09961,0.89288,0.19501,0.40588)
 TRANSFORM_TRANSLATION(objPlane,55,0.24655,-4.89373,6.28998,6.95271,-0.23356,0,-0.07898)
 TRANSFORM_ROTATION(objPlane,55,3.7054,3.82341,1.77571,-0.09961,0.8794,0.20248,0.43088)
 TRANSFORM_TRANSLATION(objPlane,56,0.30306,-5.14057,6.28998,6.77688,-0.24684,0,-0.17583)
 TRANSFORM_ROTATION(objPlane,56,3.5139,3.82341,1.77571,-0.09961,0.87355,0.14545,0.4645)
 TRANSFORM_TRANSLATION(objPlane,57,0.36399,-5.3987,6.28998,6.52025,-0.25813,0,-0.25663)
 TRANSFORM_ROTATION(objPlane,57,3.3067,3.82341,1.77571,-0.09961,0.86579,0.11379,0.4873)
 TRANSFORM_TRANSLATION(objPlane,58,0.41809,-5.66612,6.28998,6.19888,-0.26743,0,-0.32137)
 TRANSFORM_ROTATION(objPlane,58,3.0727,3.82341,1.77571,-0.09961,0.858,0.11104,0.50149)
 TRANSFORM_TRANSLATION(objPlane,59,0.4609,-5.94086,6.28998,5.82882,-0.27474,0,-0.37006)
 TRANSFORM_ROTATION(objPlane,59,2.81,3.82341,1.77571,-0.09961,0.84958,0.14299,0.50771)
 TRANSFORM_TRANSLATION(objPlane,60,0.49051,-6.22093,6.28998,5.42613,-0.28006,0,-0.40269)
 TRANSFORM_ROTATION(objPlane,60,2.5291,3.82341,1.77571,-0.09961,0.83579,0.2193,0.50335)
 TRANSFORM_TRANSLATION(objPlane,61,0.50607,-6.50432,6.28998,5.00685,-0.28339,0,-0.41928)
 TRANSFORM_ROTATION(objPlane,61,2.2585,3.82341,1.77571,-0.09961,0.80367,0.35291,0.47913)
 TRANSFORM_TRANSLATION(objPlane,62,0.50726,-6.78906,6.28998,4.58705,-0.28474,0,-0.41981)
 TRANSFORM_ROTATION(objPlane,62,2.0561,3.82341,1.77571,-0.09961,0.72603,0.54827,0.41507)
 TRANSFORM_TRANSLATION(objPlane,63,0.49412,-7.07315,6.28998,4.18277,-0.28409,0,-0.40428)
 TRANSFORM_ROTATION(objPlane,63,2.0129,3.82341,1.77571,-0.09961,0.57213,0.76728,0.28971)
 TRANSFORM_TRANSLATION(objPlane,64,0.46704,-7.35461,6.28998,3.81006,-0.28146,0,-0.3727)
 TRANSFORM_ROTATION(objPlane,64,2.2154,3.82341,1.77571,-0.09961,0.36139,0.92476,0.11923)
 TRANSFORM_TRANSLATION(objPlane,65,0.42698,-7.63144,6.28998,3.48499,-0.27683,0,-0.32507)
 TRANSFORM_ROTATION(objPlane,65,2.6826,3.82341,1.77571,-0.09961,0.1694,0.98463,-0.0425)
 TRANSFORM_TRANSLATION(objPlane,66,0.40685,-7.93376,6.29565,3.21278,-0.30232,0.00567,-0.27221)
 TRANSFORM_ROTATION(objPlane,66,4.1348,3.82341,1.77571,-0.09961,0.0436,0.97136,-0.23357)
 TRANSFORM_TRANSLATION(objPlane,67,0.41785,-8.27902,6.31086,2.97792,-0.34526,0.01521,-0.23487)
 TRANSFORM_ROTATION(objPlane,67,6.2453,3.82341,1.77571,-0.09961,0.02383,0.94152,-0.33612)
 TRANSFORM_TRANSLATION(objPlane,68,0.42491,-8.64627,6.33287,2.76532,-0.36725,0.02201,-0.21259)
 TRANSFORM_ROTATION(objPlane,68,7.9967,3.82341,1.77571,-0.09961,0.05173,0.92609,-0.37375)
 TRANSFORM_TRANSLATION(objPlane,69,0.42247,-9.01453,6.35897,2.55994,-0.36826,0.0261,-0.20539)
 TRANSFORM_ROTATION(objPlane,69,9.351,3.82341,1.77571,-0.09961,0.09953,0.9186,-0.38245)
 TRANSFORM_TRANSLATION(objPlane,70,0.40934,-9.36285,6.38643,2.34668,-0.34832,0.02746,-0.21326)
 TRANSFORM_ROTATION(objPlane,70,10.2749,3.82341,1.77571,-0.09961,0.15247,0.91582,-0.37151)
 TRANSFORM_TRANSLATION(objPlane,71,0.38854,-9.67025,6.41253,2.11049,-0.3074,0.0261,-0.23619)
 TRANSFORM_ROTATION(objPlane,71,10.7282,3.82341,1.77571,-0.09961,0.19937,0.91614,-0.34777)
 TRANSFORM_TRANSLATION(objPlane,72,0.36872,-9.91578,6.43454,1.83629,-0.24553,0.02201,-0.2742)
 TRANSFORM_ROTATION(objPlane,72,10.6671,3.82341,1.77571,-0.09961,0.23169,0.91838,-0.32078)
 TRANSFORM_TRANSLATION(objPlane,73,0.3658,-10.0785,6.44974,1.509,-0.16269,0.01521,-0.32728)
 TRANSFORM_ROTATION(objPlane,73,10.0544,3.82341,1.77571,-0.09961,0.24326,0.92107,-0.30404)
 TRANSFORM_TRANSLATION(objPlane,74,0.39983,-10.1374,6.45542,1.11357,-0.05889,0.00567,-0.39543)
 TRANSFORM_ROTATION(objPlane,74,8.8765,3.82341,1.77571,-0.09961,0.22765,0.92069,-0.31702)
 TRANSFORM_TRANSLATION(objPlane,75,0.59409,-9.94032,6.42479,0.55395,0.19704,-0.03062,-0.55962)
 TRANSFORM_ROTATION(objPlane,75,8.4962,3.82341,1.77571,-0.09961,0.15077,0.89496,-0.41992)
 TRANSFORM_TRANSLATION(objPlane,76,0.89913,-9.44537,6.34408,-0.19234,0.49495,-0.08071,-0.74629)
 TRANSFORM_ROTATION(objPlane,76,9.2222,3.82341,1.77571,-0.09961,0.0918,0.83032,-0.54967)
 TRANSFORM_TRANSLATION(objPlane,77,1.06553,-8.7968,6.23001,-1.03001,0.64857,-0.11407,-0.83768)
 TRANSFORM_ROTATION(objPlane,77,9.6982,3.82341,1.77571,-0.09961,0.08761,0.75408,-0.65091)
 TRANSFORM_TRANSLATION(objPlane,78,1.07011,-8.13889,6.09933,-1.86381,0.65792,-0.13068,-0.83379)
 TRANSFORM_ROTATION(objPlane,78,9.8494,3.82341,1.77571,-0.09961,0.11793,0.67328,-0.72992)
 TRANSFORM_TRANSLATION(objPlane,79,0.91118,-7.6159,5.96878,-2.59844,0.52298,-0.13056,-0.73464)
 TRANSFORM_ROTATION(objPlane,79,9.6681,3.82341,1.77571,-0.09961,0.16764,0.59033,-0.78956)
 TRANSFORM_TRANSLATION(objPlane,80,0.77247,-7.2281,5.80952,-3.24725,0.3878,-0.15925,-0.64881)
 TRANSFORM_ROTATION(objPlane,80,9.1795,3.82341,1.77571,-0.09961,0.22352,0.50709,-0.8324)
 TRANSFORM_TRANSLATION(objPlane,81,0.74419,-6.87929,5.61042,-3.87375,0.34881,-0.1991,-0.6265)
 TRANSFORM_ROTATION(objPlane,81,8.4233,3.82341,1.77571,-0.09961,0.27191,0.42599,-0.8629)
 TRANSFORM_TRANSLATION(objPlane,82,0.68979,-6.5691,5.41469,-4.45795,0.31019,-0.19573,-0.58419)
 TRANSFORM_ROTATION(objPlane,82,7.446,3.82341,1.77571,-0.09961,0.29659,0.35,-0.88856)
 TRANSFORM_TRANSLATION(objPlane,83,0.60709,-6.29718,5.26556,-4.97984,0.27192,-0.14914,-0.52189)
 TRANSFORM_ROTATION(objPlane,83,6.3038,3.82341,1.77571,-0.09961,0.27382,0.28211,-0.91947)
 TRANSFORM_TRANSLATION(objPlane,84,0.50153,-6.06315,5.20624,-5.41943,0.23403,-0.05932,-0.43959)
 TRANSFORM_ROTATION(objPlane,84,5.0904,3.82341,1.77571,-0.09961,0.15898,0.22359,-0.96163)
 TRANSFORM_TRANSLATION(objPlane,85,0.45163,-5.87943,5.39894,-5.78424,0.18373,0.1927,-0.36481)
 TRANSFORM_ROTATION(objPlane,85,4.9449,3.82341,1.77571,-0.09961,-0.07059,0.00018,-0.99751)
 TRANSFORM_TRANSLATION(objPlane,86,0.5796,-5.74624,5.87452,-6.08758,0.13318,0.47558,-0.30335)
 TRANSFORM_ROTATION(objPlane,86,5.6975,3.82341,1.77571,-0.09961,-0.20163,-0.20273,-0.95825)
 TRANSFORM_TRANSLATION(objPlane,87,0.65506,-5.645,6.47922,-6.31821,0.10124,0.6047,-0.23063)
 TRANSFORM_ROTATION(objPlane,87,5.6045,3.82341,1.77571,-0.09961,-0.28031,-0.26326,-0.9231)
 TRANSFORM_TRANSLATION(objPlane,88,0.60473,-5.55709,7.05928,-6.46485,0.08791,0.58006,-0.14664)
 TRANSFORM_ROTATION(objPlane,88,4.4369,3.82341,1.77571,-0.09961,-0.36602,-0.24639,-0.89739)
 TRANSFORM_TRANSLATION(objPlane,89,0.41551,-5.4639,7.46094,-6.51623,0.09319,0.40165,-0.05138)
 TRANSFORM_ROTATION(objPlane,89,2.2497,3.82341,1.77571,-0.09961,-0.57425,-0.05868,-0.81658)
 TRANSFORM_TRANSLATION(objPlane,90,0.26417,-5.36522,7.70595,-6.51225,0.09868,0.24501,0.00398)
 TRANSFORM_ROTATION(objPlane,90,1.2346,3.82341,1.77571,-0.09961,-0.83024,0.43739,-0.34555)
 TRANSFORM_TRANSLATION(objPlane,91,0.23554,-5.27226,7.92209,-6.50125,0.09296,0.21614,0.011)
 TRANSFORM_ROTATION(objPlane,91,1.2638,3.82341,1.77571,-0.09961,-0.8365,0.44828,-0.31515)
 TRANSFORM_TRANSLATION(objPlane,92,0.21261,-5.18353,8.11458,-6.48463,0.08873,0.1925,0.01662)
 TRANSFORM_ROTATION(objPlane,92,1.2681,3.82341,1.77571,-0.09961,-0.84066,0.45602,-0.29214)
 TRANSFORM_TRANSLATION(objPlane,93,0.19529,-5.09753,8.28867,-6.46379,0.086,0.17409,0.02084)
 TRANSFORM_ROTATION(objPlane,93,1.247,3.82341,1.77571,-0.09961,-0.84356,0.46159,-0.27449)
 TRANSFORM_TRANSLATION(objPlane,94,0.1834,-5.01277,8.44958,-6.44014,0.08476,0.16091,0.02365)
 TRANSFORM_ROTATION(objPlane,94,1.1997,3.82341,1.77571,-0.09961,-0.84576,0.46551,-0.26077)
 TRANSFORM_TRANSLATION(objPlane,95,0.17679,-4.92775,8.60254,-6.41509,0.08502,0.15297,0.02505)
 TRANSFORM_ROTATION(objPlane,95,1.1261,3.82341,1.77571,-0.09961,-0.84756,0.46821,-0.24988)
 TRANSFORM_TRANSLATION(objPlane,96,0.17531,-4.84098,8.7528,-6.39004,0.08677,0.15025,0.02505)
 TRANSFORM_ROTATION(objPlane,96,1.026,3.82341,1.77571,-0.09961,-0.84913,0.47003,-0.24097)
 TRANSFORM_TRANSLATION(objPlane,97,0.17889,-4.75096,8.90557,-6.36639,0.09001,0.15277,0.02365)
 TRANSFORM_ROTATION(objPlane,97,0.8992,3.82341,1.77571,-0.09961,-0.85063,0.47113,-0.23336)
 TRANSFORM_TRANSLATION(objPlane,98,0.18757,-4.65621,9.0661,-6.34555,0.09475,0.16053,0.02084)
 TRANSFORM_ROTATION(objPlane,98,0.7458,3.82341,1.77571,-0.09961,-0.85215,0.47174,-0.22651)
 TRANSFORM_TRANSLATION(objPlane,99,0.20145,-4.55523,9.23961,-6.32893,0.10098,0.17351,0.01662)
 TRANSFORM_ROTATION(objPlane,99,0.5657,3.82341,1.77571,-0.09961,-0.85374,0.47196,-0.21996)
 TRANSFORM_TRANSLATION(objPlane,100,0.22068,-4.44652,9.43134,-6.31793,0.10871,0.19173,0.011)
 TRANSFORM_ROTATION(objPlane,100,0.359,3.82341,1.77571,-0.09961,-0.85543,0.47194,-0.21336)
 TRANSFORM_TRANSLATION(objPlane,101,0.24541,-4.32859,9.64652,-6.31395,0.11793,0.21518,0.00398)
 TRANSFORM_ROTATION(objPlane,101,0.1256,3.82341,1.77571,-0.09961,-0.85704,0.47184,-0.20696)
 TRANSFORM_TRANSLATION(objPlane,102,0.27247,-4.22,9.8964,-6.31688,0.1086,0.24988,-0.00293)
 TRANSFORM_ROTATION(objPlane,102,0.0324,3.82341,1.77571,-0.09961,-0.22631,0.14952,0.96251)
 TRANSFORM_TRANSLATION(objPlane,103,0.30093,-4.12601,10.1822,-6.32443,0.09399,0.28577,-0.00755)
 TRANSFORM_ROTATION(objPlane,103,0.2266,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,104,0.32788,-4.02523,10.494,-6.33476,0.10078,0.31184,-0.01033)
 TRANSFORM_ROTATION(objPlane,104,0.615,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,105,0.35268,-3.89627,10.8221,-6.34601,0.12897,0.32806,-0.01125)
 TRANSFORM_ROTATION(objPlane,105,1.1976,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,106,0.37928,-3.71771,11.1565,-6.35633,0.17855,0.33446,-0.01033)
 TRANSFORM_ROTATION(objPlane,106,1.9744,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,107,0.41461,-3.46818,11.4876,-6.36389,0.24954,0.33102,-0.00755)
 TRANSFORM_ROTATION(objPlane,107,2.9454,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,108,0.46679,-3.12625,11.8053,-6.36681,0.34193,0.31775,-0.00293)
 TRANSFORM_ROTATION(objPlane,108,4.1106,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,109,0.60649,-2.63343,12.1556,-6.3195,0.49282,0.35031,0.04732)
 TRANSFORM_ROTATION(objPlane,109,6.7992,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,110,0.76846,-1.98877,12.5568,-6.2012,0.64466,0.40118,0.1183)
 TRANSFORM_ROTATION(objPlane,110,10.0096,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,111,0.84831,-1.25719,12.9578,-6.04741,0.73158,0.40097,0.15379)
 TRANSFORM_ROTATION(objPlane,111,11.9116,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,112,0.84484,-0.50364,13.3074,-5.89362,0.75355,0.34966,0.15379)
 TRANSFORM_ROTATION(objPlane,112,12.5053,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,113,0.76163,0.20696,13.5547,-5.77532,0.7106,0.24726,0.1183)
 TRANSFORM_ROTATION(objPlane,113,11.7905,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,114,0.6118,0.80968,13.6485,-5.728,0.60271,0.09377,0.04732)
 TRANSFORM_ROTATION(objPlane,114,9.7674,3.82341,1.77571,-0.09961,-0.22627,0.14959,0.96251)
 TRANSFORM_TRANSLATION(objPlane,115,0.50906,1.28969,13.4791,-5.73527,0.48002,-0.16934,-0.00727)
 TRANSFORM_ROTATION(objPlane,115,8.4603,3.82341,1.77571,-0.09961,-0.27975,0.05629,0.95842)
 TRANSFORM_TRANSLATION(objPlane,116,0.60451,1.696,13.032,-5.75541,0.40631,-0.44714,-0.02014)
 TRANSFORM_ROTATION(objPlane,116,8.5819,3.82341,1.77571,-0.09961,-0.36688,-0.09547,0.92536)
 TRANSFORM_TRANSLATION(objPlane,117,0.73104,2.05935,12.3984,-5.78589,0.36335,-0.63362,-0.03048)
 TRANSFORM_ROTATION(objPlane,117,8.3051,3.82341,1.77571,-0.09961,-0.44501,-0.21077,0.87037)
 TRANSFORM_TRANSLATION(objPlane,118,0.80986,2.4105,11.6696,-5.82418,0.35115,-0.72877,-0.03829)
 TRANSFORM_ROTATION(objPlane,118,7.5696,3.82341,1.77571,-0.09961,-0.55072,-0.29186,0.78199)
 TRANSFORM_TRANSLATION(objPlane,119,0.82176,2.78021,10.937,-5.86776,0.36971,-0.7326,-0.04359)
 TRANSFORM_ROTATION(objPlane,119,6.4694,3.82341,1.77571,-0.09961,-0.72776,-0.3121,0.61069)
 TRANSFORM_TRANSLATION(objPlane,120,0.77064,3.19923,10.2919,-5.91412,0.41902,-0.6451,-0.04635)
 TRANSFORM_ROTATION(objPlane,120,5.6011,3.82341,1.77571,-0.09961,-0.95939,-0.16745,0.22703)
 TRANSFORM_TRANSLATION(objPlane,121,0.84148,3.76051,9.66827,-5.97843,0.56129,-0.62363,-0.06431)
 TRANSFORM_ROTATION(objPlane,121,10.6848,3.82341,1.77571,-0.09961,-0.75592,0.53841,-0.37243)
 TRANSFORM_TRANSLATION(objPlane,122,0.96624,4.44252,8.98918,-6.06396,0.68201,-0.6791,-0.08553)
 TRANSFORM_ROTATION(objPlane,122,20.7585,3.82341,1.77571,-0.09961,-0.46513,0.74642,-0.47593)
 TRANSFORM_TRANSLATION(objPlane,123,0.93832,5.10424,8.32955,-6.15031,0.66172,-0.65963,-0.08635)
 TRANSFORM_ROTATION(objPlane,123,25.7283,3.82341,1.77571,-0.09961,-0.27343,0.82934,-0.48727)
 TRANSFORM_TRANSLATION(objPlane,124,0.75788,5.60468,7.76432,-6.21708,0.50044,-0.56523,-0.06677)
 TRANSFORM_ROTATION(objPlane,124,23.9631,3.82341,1.77571,-0.09961,-0.12461,0.88923,-0.44017)
 TRANSFORM_TRANSLATION(objPlane,125,0.44352,5.80282,7.36843,-6.24387,0.19815,-0.39589,-0.02679)
 TRANSFORM_ROTATION(objPlane,125,14.7919,3.82341,1.77571,-0.09961,-0.02327,0.95645,-0.29098)
 TRANSFORM_TRANSLATION(objPlane,126,0.24833,5.76369,7.1303,-6.18533,-0.03913,-0.23813,0.05854)
 TRANSFORM_ROTATION(objPlane,126,8.1045,3.82341,1.77571,-0.09961,0.04026,0.98401,0.17351)
 TRANSFORM_TRANSLATION(objPlane,127,0.25059,5.65624,6.97354,-6.022,-0.10745,-0.15676,0.16333)
 TRANSFORM_ROTATION(objPlane,127,8.4487,3.82341,1.77571,-0.09961,0.03065,0.8884,0.45805)
 TRANSFORM_TRANSLATION(objPlane,128,0.31266,5.49539,6.87589,-5.77231,-0.16085,-0.09765,0.24969)
 TRANSFORM_ROTATION(objPlane,128,8.9405,3.82341,1.77571,-0.09961,-0.06523,0.77566,0.62777)
 TRANSFORM_TRANSLATION(objPlane,129,0.37988,5.29605,6.81508,-5.4547,-0.19935,-0.06081,0.31761)
 TRANSFORM_ROTATION(objPlane,129,9.2139,3.82341,1.77571,-0.09961,-0.1997,0.68165,0.70388)
 TRANSFORM_TRANSLATION(objPlane,130,0.43196,5.07312,6.76886,-5.08761,-0.22292,-0.04622,0.36709)
 TRANSFORM_ROTATION(objPlane,130,9.0602,3.82341,1.77571,-0.09961,-0.3423,0.61061,0.71413)
 TRANSFORM_TRANSLATION(objPlane,131,0.46374,4.84153,6.71495,-4.68947,-0.23159,-0.0539,0.39814)
 TRANSFORM_ROTATION(objPlane,131,8.3527,3.82341,1.77571,-0.09961,-0.47874,0.5562,0.6793)
 TRANSFORM_TRANSLATION(objPlane,132,0.47595,4.61619,6.63111,-4.27872,-0.22534,-0.08385,0.41075)
 TRANSFORM_ROTATION(objPlane,132,7.0144,3.82341,1.77571,-0.09961,-0.61003,0.50655,0.60931)
 TRANSFORM_TRANSLATION(objPlane,133,0.47346,4.412,6.49506,-3.8738,-0.20418,-0.13605,0.40492)
 TRANSFORM_ROTATION(objPlane,133,5.0377,3.82341,1.77571,-0.09961,-0.7611,0.43265,0.48326)
 TRANSFORM_TRANSLATION(objPlane,134,0.46635,4.24389,6.28454,-3.49313,-0.16811,-0.21052,0.38066)
 TRANSFORM_ROTATION(objPlane,134,2.7493,3.82341,1.77571,-0.09961,-0.98187,0.1692,0.08552)
 TRANSFORM_TRANSLATION(objPlane,135,0.52953,4.09704,5.9751,-3.0893,-0.14686,-0.30943,0.40383)
 TRANSFORM_ROTATION(objPlane,135,2.5831,3.82341,1.77571,-0.09961,-0.86615,-0.22565,-0.44594)
 TRANSFORM_TRANSLATION(objPlane,136,0.63128,3.94994,5.57733,-2.62169,-0.1471,-0.39777,0.46761)
 TRANSFORM_ROTATION(objPlane,136,3.1017,3.82341,1.77571,-0.09961,-0.86615,-0.22565,-0.44594)
 TRANSFORM_TRANSLATION(objPlane,137,0.69339,3.80748,5.12149,-2.119,-0.14246,-0.45584,0.50269)
 TRANSFORM_ROTATION(objPlane,137,3.3543,3.82341,1.77571,-0.09961,-0.86615,-0.22565,-0.44594)
 TRANSFORM_TRANSLATION(objPlane,138,0.71467,3.67456,4.63783,-1.60992,-0.13292,-0.48365,0.50909)
 TRANSFORM_ROTATION(objPlane,138,3.3409,3.82341,1.77571,-0.09961,-0.86615,-0.22565,-0.44594)
 TRANSFORM_TRANSLATION(objPlane,139,0.69467,3.55607,4.15664,-1.12312,-0.11849,-0.4812,0.4868)
 TRANSFORM_ROTATION(objPlane,139,3.0615,3.82341,1.77571,-0.09961,-0.86615,-0.22565,-0.44594)
 TRANSFORM_TRANSLATION(objPlane,140,0.63317,3.4569,3.70816,-0.68729,-0.09917,-0.44847,0.43583)
 TRANSFORM_ROTATION(objPlane,140,2.5162,3.82341,1.77571,-0.09961,-0.86615,-0.22565,-0.44594)
 TRANSFORM_TRANSLATION(objPlane,141,0.53016,3.38195,3.32267,-0.33112,-0.07495,-0.38549,0.35617)
 TRANSFORM_ROTATION(objPlane,141,1.7048,3.82341,1.77571,-0.09961,-0.86615,-0.22565,-0.44594)
 TRANSFORM_TRANSLATION(objPlane,142,0.3859,3.3361,3.03044,-0.0833,-0.04585,-0.29224,0.24782)
 TRANSFORM_ROTATION(objPlane,142,0.6274,3.82341,1.77571,-0.09961,-0.86615,-0.22565,-0.44594)
 TRANSFORM_TRANSLATION(objPlane,143,0.26034,3.31062,2.82023,0.06816,-0.02548,-0.2102,0.15146)
 TRANSFORM_ROTATION(objPlane,143,1.4264,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,144,0.19055,3.29251,2.65646,0.16387,-0.0181,-0.16377,0.09571)
 TRANSFORM_ROTATION(objPlane,144,3.8621,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,145,0.13555,3.2803,2.53282,0.21807,-0.01222,-0.12364,0.0542)
 TRANSFORM_ROTATION(objPlane,145,5.6723,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,146,0.09409,3.27247,2.443,0.24499,-0.00782,-0.08982,0.02693)
 TRANSFORM_ROTATION(objPlane,146,6.8568,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,147,0.06402,3.26755,2.38071,0.25889,-0.00492,-0.0623,0.01389)
 TRANSFORM_ROTATION(objPlane,147,7.4157,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,148,0.04391,3.26404,2.33963,0.27399,-0.00351,-0.04108,0.0151)
 TRANSFORM_ROTATION(objPlane,148,7.3491,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,149,0.04038,3.26046,2.31346,0.30454,-0.00358,-0.02617,0.03055)
 TRANSFORM_ROTATION(objPlane,149,6.6568,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,150,0.06296,3.25531,2.29591,0.36478,-0.00515,-0.01756,0.06024)
 TRANSFORM_ROTATION(objPlane,150,5.3389,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,151,0.1056,3.2471,2.28065,0.46895,-0.00821,-0.01525,0.10417)
 TRANSFORM_ROTATION(objPlane,151,3.3955,3.82341,1.77571,-0.09961,0.86615,0.22565,0.44594)
 TRANSFORM_TRANSLATION(objPlane,152,0.17305,3.23562,2.26639,0.64103,-0.01149,-0.01426,0.17208)
 TRANSFORM_ROTATION(objPlane,152,2.052,3.82341,1.77571,-0.09961,0.72439,-0.29777,0.62176)
 TRANSFORM_TRANSLATION(objPlane,153,0.23714,3.22232,2.25567,0.87755,-0.0133,-0.01072,0.23652)
 TRANSFORM_ROTATION(objPlane,153,3.0962,3.82341,1.77571,-0.09961,0.25179,-0.79029,0.55861)
 TRANSFORM_TRANSLATION(objPlane,154,0.2745,3.20823,2.24799,1.15159,-0.01409,-0.00768,0.27403)
 TRANSFORM_ROTATION(objPlane,154,4.2222,3.82341,1.77571,-0.09961,0.07504,-0.8758,0.4768)
 TRANSFORM_TRANSLATION(objPlane,155,0.28499,3.19439,2.24285,1.43619,-0.01384,-0.00515,0.28461)
 TRANSFORM_ROTATION(objPlane,155,4.8461,3.82341,1.77571,-0.09961,0.01332,-0.89812,0.43953)
 TRANSFORM_TRANSLATION(objPlane,156,0.26856,3.18183,2.23972,1.70444,-0.01256,-0.00312,0.26825)
 TRANSFORM_ROTATION(objPlane,156,4.8654,3.82341,1.77571,-0.09961,-0.00722,-0.9061,0.423)
 TRANSFORM_TRANSLATION(objPlane,157,0.22519,3.17157,2.23812,1.92939,-0.01025,-0.0016,0.22495)
 TRANSFORM_ROTATION(objPlane,157,4.2562,3.82341,1.77571,-0.09961,-0.01168,-0.90937,0.41581)
 TRANSFORM_TRANSLATION(objPlane,158,0.15488,3.16467,2.23753,2.08411,-0.00691,-0.00059,0.15472)
 TRANSFORM_ROTATION(objPlane,158,3.0151,3.82341,1.77571,-0.09961,-0.01201,-0.91074,0.41282)
 TRANSFORM_TRANSLATION(objPlane,159,0.05762,3.16214,2.23744,2.14167,-0.00253,-8e-05,0.05756)
 TRANSFORM_ROTATION(objPlane,159,1.1444,3.82341,1.77571,-0.09961,-0.01497,-0.91121,0.41166)