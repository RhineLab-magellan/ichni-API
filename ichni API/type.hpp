/*
* �����ߣ���¶¶
* ����ʱ�䣺2022.2.3
* �������������ͣ�������ֲ�������
*/


#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


using _EaseCurve = string;
using _TrackSpaceType = string;
using _TrackMoveType = string;
using _TrackCauculateType = string;
using _CameraViewType = string;

//���ַ���ֵ����
using UReturn = void;

//new EaseCurve(EaseCurveType)
namespace EaseCurveType {
    string Linear = "EaseCurveType.Linear";
};
//���ｫ�������ϲ���
namespace EaseCurve = EaseCurveType;

struct AnimatedFloat {
    float startValue, endValue;//��ֵֹ
    float startTime, endTime;//��ֹʱ��
    _EaseCurve animationCurve;//��������
};

//new Vector3(x,y,z)
struct Vector3
{
    float x;
    float y;
    float z;
};

//Track.TrackMoveType
namespace TrackMoveType{
    string undecided = "Track.TrackMoveType.undecided";//δ��������״ֻ̬�������Editor�У��״μ���һ��TrackGroup���������������Ϸ��˵���С��쳣����
    string quiescent = "Track.TrackMoveType.quiescent";//��̬�����Note�ӹ�����β�ˣ����һ����������λ�ã�ǰ��ͷ�ˣ���һ���������ʼλ�ã���Head��Tail��������ʼλ�ò���Ĭ�ϲ����ƶ�
    string movable = "Track.TrackMoveType.movable";//��̬�����Head��TailĬ�����趨������ǰ�ƶ�
};

//Track.TrackCauculateType
namespace TrackCauculateType {
    string distance = "Track.TrackCauculateType.distance";//ʹ�ÿռ������㣬��ӦvisibleTrackDistance
    string time = "Track.TrackCauculateType.time";//ʹ��ʱ����㣬��ӦvisibleTrackTime
};

//Track.TrackSpaceType
namespace TrackSpaceType {
    string CatmullRom = "Track.TrackSpaceType.CatmullRom";
    string BSpline = "Track.TrackSpaceType.BSpline";
    string Linear = "Track.TrackSpaceType.Linear";
};

//GameCamera.CameraViewType
namespace CameraViewType{
    string perspective = "GameCamera.CameraViewType.perspective";//͸�����
    string orthographic = "GameCamera.CameraViewType.orthographic";//�������
};

#define _CRLF "\r\n"
