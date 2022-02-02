#include "API.hpp"

int main() {
	//实例化API
	API* api = new API("text.cs");

	//谱
	api->GenerateElementFolder();
	api->GenerateTrack(12., 3.4, EaseCurveType::Linear, TrackMoveType::movable, TrackCauculateType::distance, TrackSpaceType::Linear, 7.8, 9.0);
	api->GeneratePathNode({ 1,2,3 }, { 4,5,6 }, 7.8);
	api->GenerateTap(1.2);

	//输出C#代码
	cout << api->data() << endl;

	//请按任意键继续
	system("pause");
	//程序结束
	return 0;
}