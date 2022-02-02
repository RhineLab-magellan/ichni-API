#include "API.hpp"

int main() {
	//ʵ����API
	API* api = new API("text.cs");

	//��
	api->GenerateElementFolder();
	api->GenerateTrack(12., 3.4, EaseCurveType::Linear, TrackMoveType::movable, TrackCauculateType::distance, TrackSpaceType::Linear, 7.8, 9.0);
	api->GeneratePathNode({ 1,2,3 }, { 4,5,6 }, 7.8);
	api->GenerateTap(1.2);

	//���C#����
	cout << api->data() << endl;

	//�밴���������
	system("pause");
	//�������
	return 0;
}