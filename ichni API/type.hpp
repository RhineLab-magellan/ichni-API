/*
* 创建者：菲露露
* 创建时间：2022.2.3
* 描述：各种类型，适配各种参数类型
*/


#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


typedef string _EaseCurve;
using _TrackSpaceType = string;
using _TrackMoveType = string;
using _TrackCauculateType = string;
using _CameraViewType = string;

//各种返回值类型
using UReturn = void;

//new EaseCurve(EaseCurveType)
namespace EaseCurveType {
    string Linear = "EaseCurveType.Linear";
};
//这里将他们俩合并了
namespace EaseCurve = EaseCurveType;
namespace ECT = EaseCurveType;

struct AnimatedFloat {
    float startValue, endValue;//起止值
    float startTime, endTime;//起止时间
    _EaseCurve animationCurve;//动画曲线
};
using AF = AnimatedFloat;

//new Vector3(x,y,z)
struct Vector3
{
    float x;
    float y;
    float z;
};
using V3 = Vector3;


//Track.TrackMoveType
namespace TrackMoveType{
    string undecided = "Track.TrackMoveType.undecided";//未决定，该状态只会出现在Editor中（首次加入一个TrackGroup），如果存在于游戏中说明有「异常」。
    string quiescent = "Track.TrackMoveType.quiescent";//静态轨道，Note从轨道组的尾端（最后一个轨道的最后位置）前往头端（第一个轨道的起始位置），Head和Tail都处于起始位置并且默认不会移动
    string movable = "Track.TrackMoveType.movable";//动态轨道，Head和Tail默认以设定参数向前移动
};
namespace TMT = TrackMoveType;

//Track.TrackCauculateType
namespace TrackCauculateType {
    string distance = "Track.TrackCauculateType.distance";//使用空间距离计算，对应visibleTrackDistance
    string time = "Track.TrackCauculateType.time";//使用时间计算，对应visibleTrackTime
};
namespace TCT = TrackCauculateType;

//Track.TrackSpaceType
namespace TrackSpaceType {
    string CatmullRom = "Track.TrackSpaceType.CatmullRom";
    string BSpline = "Track.TrackSpaceType.BSpline";
    string Linear = "Track.TrackSpaceType.Linear";
};
namespace TST = TrackSpaceType;

//GameCamera.CameraViewType
namespace CameraViewType{
    string perspective = "GameCamera.CameraViewType.perspective";//透视相机
    string orthographic = "GameCamera.CameraViewType.orthographic";//正交相机
};
namespace CVT = CameraViewType;

#define _CRLF "\r\n"
