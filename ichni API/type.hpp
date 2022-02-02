#pragma once

//各种返回值类型
using UReturn = void;

//浮点数
using FlexibleFloat = float;

//new EaseCurve(EaseCurveType)
enum class EaseCurveType {
    Linear
};
//这里将他们俩合并了
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

    undecided = 0,//未决定，该状态只会出现在Editor中（首次加入一个TrackGroup），如果存在于游戏中说明有「异常」。
    quiescent = 1,//静态轨道，Note从轨道组的尾端（最后一个轨道的最后位置）前往头端（第一个轨道的起始位置），Head和Tail都处于起始位置并且默认不会移动
    movable = 2//动态轨道，Head和Tail默认以设定参数向前移动
};

//Track.TrackCauculateType
enum class TrackCauculateType {
    distance = 0,//使用空间距离计算，对应visibleTrackDistance
    time = 1//使用时间计算，对应visibleTrackTime
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
    perspective = 0,//透视相机
    orthographic = 1//正交相机
};

