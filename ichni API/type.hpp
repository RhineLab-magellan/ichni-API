#pragma once

//���ַ���ֵ����
using UReturn = void;

//������
using FlexibleFloat = float;

//new EaseCurve(EaseCurveType)
enum class EaseCurveType {
    Linear
};
//���ｫ�������ϲ���
using EaseCurve = EaseCurveType;


//new Vector3(x,y,z)
struct Vector3
{
    int x;
    int y;
    int z;
};

//Track.TrackMoveType
enum class TrackMoveType
{

    undecided = 0,//δ��������״ֻ̬�������Editor�У��״μ���һ��TrackGroup���������������Ϸ��˵���С��쳣����
    quiescent = 1,//��̬�����Note�ӹ�����β�ˣ����һ����������λ�ã�ǰ��ͷ�ˣ���һ���������ʼλ�ã���Head��Tail��������ʼλ�ò���Ĭ�ϲ����ƶ�
    movable = 2//��̬�����Head��TailĬ�����趨������ǰ�ƶ�
};

//Track.TrackCauculateType
enum class TrackCauculateType {
    distance = 0,//ʹ�ÿռ������㣬��ӦvisibleTrackDistance
    time = 1//ʹ��ʱ����㣬��ӦvisibleTrackTime
};

//Track.TrackSpaceType
enum class TrackSpaceType {
    CatmullRom = 0,
    BSpline = 1,
    Linear = 2
};

//GameCamera.CameraViewType
enum class CameraViewType
{
    perspective = 0,//͸�����
    orthographic = 1//�������
};

