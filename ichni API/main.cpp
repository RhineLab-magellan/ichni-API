/*
* 创建者：菲露露
* 创建时间：2022.2.3
* 描述：测试代码（main函数）
*/

#include "API.hpp"
#include "FlexibleFloat.hpp"


int main() {
	//实例化API
	API* api = new API("text.cs");


	//谱
	api->GenerateElementFolder();
	api->GenerateGameCamera(CameraViewType::orthographic, 1.32);
	api->GenerateTrack(12.1, 13.4, EaseCurveType::Linear, TrackMoveType::movable, TrackCauculateType::distance, TrackSpaceType::Linear, 7.76, 0);
	FlexibleFloat ff;
	ff.startAdd({ 1.1,2.2,3.3,4.4,EaseCurveType::Linear });
	ff.add({ 5.5,6.6,7.7,8.8,EaseCurveType::Linear });
	ff.add({ 9.9,0.0,1.1,2.2,EaseCurveType::Linear });
	ff.add({ 3.3,4.4,5.5,6.6,EaseCurveType::Linear });
	ff.add({ 7.7,8.8,9.9,0.0,EaseCurveType::Linear });
	ff.add({ 1.1,2.2,3.3,4.4,EaseCurveType::Linear });
	ff.endAdd();
	api->ModifyGameCameraView(ff);
	api->GeneratePathNode({1,1.2,1.22}, {4.55,111.2,55.6}, 1.222);
	FlexibleFloat f1;
	FlexibleFloat f2;
	FlexibleFloat f3;
	FlexibleFloat f4;

	f1.startAdd({ 1.1,2.2,3.3,4.4,EaseCurveType::Linear });
	f2.startAdd({ 1.1,2.2,3.3,4.4,EaseCurveType::Linear });
	f3.startAdd({ 1.1,2.2,3.3,4.4,EaseCurveType::Linear });
	f4.startAdd({ 1.1,2.2,3.3,4.4,EaseCurveType::Linear });

	f1.endAdd();
	f2.endAdd();
	f3.endAdd();
	f4.endAdd();
	api->ModifyGlobalTrackColor(f1,f2,f3,f4);

	//输出C#代码
	cout << api->data() << endl;
	//请按任意键继续
	system("pause");
	//程序结束
	return 0;
}