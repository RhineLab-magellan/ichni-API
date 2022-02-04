/*
* 创建者：菲露露
* 创建时间：2022.2.3
* 描述：API类，提供所有谱面API
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "type.hpp"
#include "FlexibleFloat.hpp"
#include "Vector3List.h"
#include "FlexibleColorModifierUnitList.hpp"
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ios;
using std::to_string;


class API
{
public:
	API(string filePath):_Dat("") {
		_Fip = filePath;
	}
	~API(){}
public:

#pragma region 简化名称后的谱面API函数
    /// <summary>
    /// 生成一个游戏元素文件夹（Element Folder），功能基本等于Track Group，在下一个相同函数执行之前，所有的游戏元素（主要是Track）都会被归入改函数生成的文件夹中
    /// </summary>
    void folder() {
        _Dat += "GenerateElementFolder();";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 生成一个摄像机，依附于Element Folder，且该Element Folder只包含Track
    /// </summary>
    /// <param name="cameraViewType: 决定该相机是透视相机（3D）或者正交相机（2D）"></param>
    /// <param name="viewAngleOrSize: 如果是透视相机，设定其拍摄角度(0,180)；如果是正交相机，设定其视口大小(0,正无穷)"></param>
    /// <returns></returns>
    UReturn camera(_CameraViewType cameraViewType, float viewAngleOrSize) {
        _Dat += "GenerateGameCamera(" + cameraViewType + string(",") + to_string(viewAngleOrSize) + string("f);");
        _Dat += _CRLF;
    }

    /// <summary>
    /// 在摄像机中加入拍摄角度或视口大小的动画，依附于摄像机
    /// </summary>
    /// <param name="view: Flexible Float动画"></param>
    void cameraView(FlexibleFloat view) {
        _Dat += "ModifyGameCameraView("
            + view.data()
            + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 生成一条Track，依附于Element Folder
    /// </summary>
    /// <param name="trackStartTime: 轨道开始时间"></param>
    /// <param name="trackEndTime: 轨道结束时间"></param>
    /// <param name="trackCurve: 轨道运行的动画曲线"></param>
    /// <param name="trackMoveType: 轨道运行类型，quiescent为Note从尾部移动到头部，movable为Note固定，线移动与Note碰撞"></param>
    /// <param name="trackCauculateType: 轨道计算类型，time为时间，distance为距离，影响后面的visibleTrack(Time/Length)"></param>
    /// <param name="trackSpaceType: 轨道空间构建类型：Linear线段，CatmullRom曲线，BSpline平滑曲线"></param>
    /// <param name="visibleTrackLength: 可见的轨道长度，即能看到的轨道的部分是visibleTrackLength的时间/距离长度"></param>
    /// <param name="isClosed: 是否闭合，需要至少4个PathNode才可以设为true"></param>
    /// <returns></returns>
    UReturn track(float trackStartTime,
        float trackEndTime,
        _EaseCurve trackCurve,
        _TrackMoveType trackMoveType,
        _TrackCauculateType trackCauculateType,
        _TrackSpaceType trackSpaceType,
        float visibleTrackLength,
        bool _isClosed) {
        string isClosed;
        if (_isClosed) {
            isClosed = "true";
        }
        else {
            isClosed = "false";
        }
        _Dat += "GenerateTrack(" + to_string(trackStartTime) + "f,"
            + to_string(trackEndTime) + "f,"
            + trackCurve + ","
            + trackMoveType + ","
            + trackCauculateType + ","
            + trackSpaceType + ","
            + to_string(visibleTrackLength) + "f,"
            + isClosed + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 给轨道增加一个“复杂”的颜色修正，依附于Track
    /// </summary>
    /// <param name="flexibleColorModifierUnits：详见注解"></param>
    /// <returns></returns>
    UReturn trackColor(FlexibleColorModifierUnitList flexibleColorModifierUnits) {

    }

    /// <summary>
    /// 设定Track的材质，依附于Track
    /// </summary>
    /// <param name="texture"></param>
    void trackTexture(string trackTextureBundleName, string trackTextureName) {
        _Dat += "SetTrackTexture(" + trackTextureBundleName + ", " + trackTextureName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 设定Track的一面是否自动对着摄像机，依附于Track（默认开启）
    /// </summary>
    /// <param name="auto"></param>
    void trackAutoOrient(bool _auto) {
        string auto_;
        if (_auto) {
            auto_ = "true";
        }
        else {
            auto_ = "false";
        }
        _Dat += "SetTrackAutoOrient(" + auto_ + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 给轨道的总体宽度设定一个动画，依附于Track
    /// </summary>
    /// <param name="width"></param>
    void trackWidth(FlexibleFloat width) {
        _Dat += "ModifyGlobalTrackWidth(" + width.data() + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 给轨道的总体颜色设定一个动画，依附于Track
    /// </summary>
    /// <param name="colorR"></param>
    /// <param name="colorG"></param>
    /// <param name="colorB"></param>
    /// <param name="colorA"></param>
    void trackColor(FlexibleFloat colorR, FlexibleFloat colorG, FlexibleFloat colorB, FlexibleFloat colorA) {
        _Dat += "ModifyGlobalTrackColor(" + colorR.data() + "," + colorG.data() + "," + colorB.data() + "," + colorA.data() + ");";
        _Dat += _CRLF;
    }


    /// <summary>
    /// 创建一个PathNode，依附于Track
    /// </summary>
    /// <param name="nodePosition: PathNode的位置"></param>
    /// <param name="nodeNormal: PathNode的法线"></param>
    /// <param name="nodeSize: PathNode的体积，实际上是Track在PathNode点时的宽度"></param>
    /// <returns></returns>
    UReturn pathNode(Vector3 nodePosition, Vector3 nodeNormal, float nodeSize) {
        _Dat += "GeneratePathNode(\r\nnew Vector3("
            + to_string(nodePosition.x) + "f,"
            + to_string(nodePosition.y) + "f,"
            + to_string(nodePosition.z) + "f),\r\nnew Vector3("

            + to_string(nodeNormal.x) + "f,"
            + to_string(nodeNormal.y) + "f,"
            + to_string(nodeNormal.z) + "f),"

            + to_string(nodeSize) + "f"
            ");";
        _Dat += _CRLF;
    }



    /// <summary>
    /// 创建一个Tap Note，依附于Track
    /// </summary>
    /// <param name="exactJudgeTime  ">判定时间</param>
    /// <returns></returns>
    UReturn tap(float exactJudgeTime) {
        _Dat += "GenerateTap(" + to_string(exactJudgeTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 创建一个Stay Node，依附于Track
    /// </summary>
    /// <param name="exactJudgeTime  ">判定时间</param>
    /// <returns></returns>
    UReturn stay(float exactJudgeTime) {
        _Dat += "GenerateStay(" + to_string(exactJudgeTime) + "f);";
        _Dat += _CRLF;
    }


    /// <summary>
    /// 创建一个Hold Note，依附于Track，注意，Hold Note的时间跨度必须是被其依附的Track的子集！
    /// </summary>
    /// <param name="exactJudgeTime  ">判定时间（起点）</param>
    /// <param name="holdTime  ">需要按住的时间</param>
    /// <returns></returns>
    UReturn hold(float exactJudgeTime, float holdTime) {
        _Dat += "GenerateHold("
            + to_string(exactJudgeTime) + "f,"
            + to_string(holdTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 设定Note的外形，依附于Note
    /// </summary>
    /// <param name="noteVisualObjectBundleName  ">模型或粒子的bundle的名字</param>
    /// <param name="noteVisualObjectName  ">模型或粒子的名字</param>
    void noteVisual(string noteVisualObjectBundleName, string noteVisualObjectName) {
        _Dat += "SetNoteVisual("
            + noteVisualObjectBundleName + ","
            + noteVisualObjectName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 设定Hold Note里指示点（和Track的头部的位置一致）的外形，依附于Hold Note
    /// </summary>
    /// <param name="holdHeadPointerBundleName"></param>
    /// <param name="holdHeadPointerName"></param>
    void holdPointer(string holdHeadPointerBundleName, string holdHeadPointerName) {
        _Dat += "SetHoldHeadPointer("
            + holdHeadPointerBundleName + ","
            + holdHeadPointerName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 设定Hold Note的Track的一面是否自动对着摄像机，依附于Hold Note
    /// </summary>
    /// <param name="auto"></param>
    void holdTrackAutoOrient(bool _auto) {
        string auto_;
        if (_auto) {
            auto_ = "true";
        }
        else {
            auto_ = "false";
        }

        _Dat += "SetHoldTrackAutoOrient(" + auto_ + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Note生成效果（基础），依附于Note
    /// </summary>
    /// <param name="generateTime"></param>
    void addEffectBase(float generateTime) {
        _Dat += "AddNoteGenerateEffectBase(" + to_string(generateTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Note生成效果（粒子），依附于Note
    /// </summary>
    /// <param name="particleObjectBundleName: 粒子的bundle的名字"></param>
    /// <param name="particleObjectName: 粒子物体的名字"></param>
    /// <param name="generateTime: 生成时间，即在Note判定时间(exactJudgeTime)的generateTime秒前生成这个效果，同时Note出现"></param>
    void addEffectCreateParticles(string particleObjectBundleName, string particleObjectName, float generateTime) {
        _Dat += "AddNoteGenerateEffectCreateParticles("
            + particleObjectBundleName + ","
            + particleObjectName + ","
            + to_string(generateTime)
            + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Hold Note生成效果（延伸），从起点在effectTime秒中逐渐扩展到终点，依附于Hold Note
    /// </summary>
    /// <param name="effectTime: 效果持续时间"></param>
    /// <param name="generateTime: 生成时间"></param>
    void addEffectHoldTrackExpand(float effectTime, float generateTime) {
        _Dat += "AddNoteGenerateEffectHoldTrackExpand("
            + to_string(effectTime) + "f,"
            + to_string(generateTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Note Perfect判定效果（粒子），依附于Note
    /// </summary>
    /// <param name="particleObjectBundleName: 粒子的bundle的名字"></param>
    /// <param name="particleObjectName: 粒子物体的名字"></param>
    void addPerfectEffectCreateParticles(string particleObjectBundleName, string particleObjectName) {
        _Dat += "AddNoteJudgePerfectEffectCreateParticles("
            + particleObjectBundleName + ","
            + particleObjectName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Note Miss判定效果（淡出），依附于Note
    /// </summary>
    /// <param name="effectTime  ">效果持续时间</param>
    void addMissEffectColorFade(float effectTime) {
        _Dat += "AddNoteJudgeMissEffectColorFade(" + to_string(effectTime) + "f);";
        _Dat += _CRLF;
    }



    /// <summary>
    /// 生成一个Movement动画，移动物体，依附于所有实体物体（模型，Note）和PathNode
    /// </summary>
    /// <param name="trackStartTime  ">开始时间</param>
    /// <param name="trackEndTime  ">结束时间</param>
    /// <param name="trackSpaceType  ">轨道空间类型</param>
    /// <param name="isClosed  ">是否闭合</param>
    /// <param name="movementNodePositions  ">轨道点的集合</param>
    /// <param name="movementPercent  ">在Movement轨道上的百分比的动画（比如从0到0.5即从开头到中点）</param>
    /// <returns></returns>
    UReturn movement(float trackStartTime, float trackEndTime, _TrackSpaceType trackSpaceType, bool _isClosed, Vector3List movementNodePositions, FlexibleFloat movementPercent) {
        string isClosed;
        if (_isClosed) {
            isClosed = "true";
        }
        else {
            isClosed = "false";
        }

        _Dat += "GenerateMovement("
            + to_string(trackStartTime) + "f,"
            + to_string(trackStartTime) + "f"
            + trackSpaceType + ","
            + isClosed + ","
            + movementNodePositions.data() + ","
            + movementPercent.data() + ");"
            ;
        _Dat += _CRLF;
    }

    /// <summary>
    /// 生成一个Swirl动画，旋转物体，依附于所有实体物体（模型，Note）
    /// </summary>
    /// <param name="swirlX  ">欧拉角X轴动画</param>
    /// <param name="swirlY  ">欧拉角Y轴动画</param>
    /// <param name="swirlZ  ">欧拉角Z轴动画</param>
    /// <returns></returns>
    UReturn swirl(FlexibleFloat swirlX, FlexibleFloat swirlY, FlexibleFloat swirlZ) {
        _Dat += "GenerateSwirl(" + swirlX.data() + "," + swirlY.data() + "," + swirlZ.data() + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 生成一个Scale动画，缩放物体，依附于所有实体物体（模型，Note）
    /// </summary>
    /// <param name="scaleX  ">缩放X轴动画</param>
    /// <param name="scaleY  ">缩放Y轴动画</param>
    /// <param name="scaleZ  ">缩放Z轴动画</param>
    /// <returns></returns>
    UReturn scale(FlexibleFloat scaleX, FlexibleFloat scaleY, FlexibleFloat scaleZ) {
        _Dat += "GenerateScale(" + scaleX.data() + "," + scaleY.data() + "," + scaleZ.data() + ");";
        _Dat += _CRLF;
    }

#pragma endregion

#pragma region 原谱面API函数
	/// <summary>
    /// 生成一个游戏元素文件夹（Element Folder），功能基本等于Track Group，在下一个相同函数执行之前，所有的游戏元素（主要是Track）都会被归入改函数生成的文件夹中
    /// </summary>
	void GenerateElementFolder(){
        _Dat += "GenerateElementFolder();";
        _Dat += _CRLF;
	}

    /// <summary>
    /// 生成一个摄像机，依附于Element Folder，且该Element Folder只包含Track
    /// </summary>
    /// <param name="cameraViewType: 决定该相机是透视相机（3D）或者正交相机（2D）"></param>
    /// <param name="viewAngleOrSize: 如果是透视相机，设定其拍摄角度(0,180)；如果是正交相机，设定其视口大小(0,正无穷)"></param>
    /// <returns></returns>
    UReturn GenerateGameCamera(_CameraViewType cameraViewType, float viewAngleOrSize){
        _Dat += "GenerateGameCamera(" + cameraViewType + string(",")+to_string(viewAngleOrSize)+string("f);");
        _Dat += _CRLF;
    }

    /// <summary>
    /// 在摄像机中加入拍摄角度或视口大小的动画，依附于摄像机
    /// </summary>
    /// <param name="view: Flexible Float动画"></param>
    void ModifyGameCameraView(FlexibleFloat view){
        _Dat += "ModifyGameCameraView("
            + view.data()
            +");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 生成一条Track，依附于Element Folder
    /// </summary>
    /// <param name="trackStartTime: 轨道开始时间"></param>
    /// <param name="trackEndTime: 轨道结束时间"></param>
    /// <param name="trackCurve: 轨道运行的动画曲线"></param>
    /// <param name="trackMoveType: 轨道运行类型，quiescent为Note从尾部移动到头部，movable为Note固定，线移动与Note碰撞"></param>
    /// <param name="trackCauculateType: 轨道计算类型，time为时间，distance为距离，影响后面的visibleTrack(Time/Length)"></param>
    /// <param name="trackSpaceType: 轨道空间构建类型：Linear线段，CatmullRom曲线，BSpline平滑曲线"></param>
    /// <param name="visibleTrackLength: 可见的轨道长度，即能看到的轨道的部分是visibleTrackLength的时间/距离长度"></param>
    /// <param name="isClosed: 是否闭合，需要至少4个PathNode才可以设为true"></param>
    /// <returns></returns>
    UReturn GenerateTrack(float trackStartTime,
        float trackEndTime,
        _EaseCurve trackCurve,
        _TrackMoveType trackMoveType,
        _TrackCauculateType trackCauculateType,
        _TrackSpaceType trackSpaceType,
        float visibleTrackLength,
        bool _isClosed){
        string isClosed;
        if (_isClosed) {
            isClosed = "true";
        }
        else {
            isClosed = "false";
        }
        _Dat += "GenerateTrack(" + to_string(trackStartTime) + "f,"
            + to_string(trackEndTime) + "f,"
            + trackCurve+","
            + trackMoveType + ","
            + trackCauculateType + ","
            + trackSpaceType + ","
            + to_string(visibleTrackLength) + "f,"
        +isClosed + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 给轨道增加一个“复杂”的颜色修正，依附于Track
    /// </summary>
    /// <param name="flexibleColorModifierUnits：详见注解"></param>
    /// <returns></returns>
    UReturn GenerateTrackColorModifier(FlexibleColorModifierUnitList flexibleColorModifierUnits) {

    }

    /// <summary>
    /// 设定Track的材质，依附于Track
    /// </summary>
    /// <param name="texture"></param>
    void SetTrackTexture(string trackTextureBundleName, string trackTextureName) {
        _Dat += "SetTrackTexture("+ trackTextureBundleName +", "+ trackTextureName +");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 设定Track的一面是否自动对着摄像机，依附于Track（默认开启）
    /// </summary>
    /// <param name="auto"></param>
    void SetTrackAutoOrient(bool _auto){
        string auto_;
        if (_auto) {
            auto_ = "true";
        }
        else {
            auto_ = "false";
        }
        _Dat += "SetTrackAutoOrient("+ auto_ +");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 给轨道的总体宽度设定一个动画，依附于Track
    /// </summary>
    /// <param name="width"></param>
    void ModifyGlobalTrackWidth(FlexibleFloat width){
        _Dat += "ModifyGlobalTrackWidth(" + width.data() + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 给轨道的总体颜色设定一个动画，依附于Track
    /// </summary>
    /// <param name="colorR"></param>
    /// <param name="colorG"></param>
    /// <param name="colorB"></param>
    /// <param name="colorA"></param>
    void ModifyGlobalTrackColor(FlexibleFloat colorR, FlexibleFloat colorG, FlexibleFloat colorB, FlexibleFloat colorA){
        _Dat += "ModifyGlobalTrackColor(" + colorR.data() + ","+ colorG.data() + "," + colorB.data()+","+ colorA.data() + ");";
        _Dat += _CRLF;
    }


    /// <summary>
    /// 创建一个PathNode，依附于Track
    /// </summary>
    /// <param name="nodePosition: PathNode的位置"></param>
    /// <param name="nodeNormal: PathNode的法线"></param>
    /// <param name="nodeSize: PathNode的体积，实际上是Track在PathNode点时的宽度"></param>
    /// <returns></returns>
    UReturn GeneratePathNode(Vector3 nodePosition, Vector3 nodeNormal, float nodeSize){
        _Dat += "GeneratePathNode(\r\nnew Vector3("
            + to_string(nodePosition.x) + "f," 
            + to_string(nodePosition.y) + "f,"
            + to_string(nodePosition.z) + "f),\r\nnew Vector3("

            + to_string(nodeNormal.x) + "f,"
            + to_string(nodeNormal.y) + "f,"
            + to_string(nodeNormal.z) + "f),"

            + to_string(nodeSize) +"f"
            ");";
        _Dat += _CRLF;
    }



    /// <summary>
    /// 创建一个Tap Note，依附于Track
    /// </summary>
    /// <param name="exactJudgeTime  ">判定时间</param>
    /// <returns></returns>
    UReturn GenerateTap(float exactJudgeTime){
        _Dat += "GenerateTap(" + to_string(exactJudgeTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 创建一个Stay Node，依附于Track
    /// </summary>
    /// <param name="exactJudgeTime  ">判定时间</param>
    /// <returns></returns>
    UReturn GenerateStay(float exactJudgeTime){
        _Dat += "GenerateStay(" + to_string(exactJudgeTime) + "f);";
        _Dat += _CRLF;
    }


    /// <summary>
    /// 创建一个Hold Note，依附于Track，注意，Hold Note的时间跨度必须是被其依附的Track的子集！
    /// </summary>
    /// <param name="exactJudgeTime  ">判定时间（起点）</param>
    /// <param name="holdTime  ">需要按住的时间</param>
    /// <returns></returns>
    UReturn GenerateHold(float exactJudgeTime, float holdTime){
        _Dat += "GenerateHold(" 
            + to_string(exactJudgeTime) + "f,"
            + to_string(holdTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 设定Note的外形，依附于Note
    /// </summary>
    /// <param name="noteVisualObjectBundleName  ">模型或粒子的bundle的名字</param>
    /// <param name="noteVisualObjectName  ">模型或粒子的名字</param>
    void SetNoteVisual(string noteVisualObjectBundleName, string noteVisualObjectName){
        _Dat += "SetNoteVisual("
            + noteVisualObjectBundleName + ","
            + noteVisualObjectName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 设定Hold Note里指示点（和Track的头部的位置一致）的外形，依附于Hold Note
    /// </summary>
    /// <param name="holdHeadPointerBundleName"></param>
    /// <param name="holdHeadPointerName"></param>
    void SetHoldHeadPointer(string holdHeadPointerBundleName, string holdHeadPointerName){
        _Dat += "SetHoldHeadPointer("
            + holdHeadPointerBundleName + ","
            + holdHeadPointerName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 设定Hold Note的Track的一面是否自动对着摄像机，依附于Hold Note
    /// </summary>
    /// <param name="auto"></param>
    void SetHoldTrackAutoOrient(bool _auto){
        string auto_;
        if (_auto) {
            auto_ = "true";
        }
        else {
            auto_ = "false";
        }

        _Dat += "SetHoldTrackAutoOrient("+ auto_ +");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Note生成效果（基础），依附于Note
    /// </summary>
    /// <param name="generateTime"></param>
    void AddNoteGenerateEffectBase(float generateTime){
        _Dat += "AddNoteGenerateEffectBase(" + to_string(generateTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Note生成效果（粒子），依附于Note
    /// </summary>
    /// <param name="particleObjectBundleName: 粒子的bundle的名字"></param>
    /// <param name="particleObjectName: 粒子物体的名字"></param>
    /// <param name="generateTime: 生成时间，即在Note判定时间(exactJudgeTime)的generateTime秒前生成这个效果，同时Note出现"></param>
    void AddNoteGenerateEffectCreateParticles(string particleObjectBundleName, string particleObjectName, float generateTime){
        _Dat += "AddNoteGenerateEffectCreateParticles("
            + particleObjectBundleName + ","
            + particleObjectName +","
            + to_string(generateTime)
            + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Hold Note生成效果（延伸），从起点在effectTime秒中逐渐扩展到终点，依附于Hold Note
    /// </summary>
    /// <param name="effectTime: 效果持续时间"></param>
    /// <param name="generateTime: 生成时间"></param>
    void AddNoteGenerateEffectHoldTrackExpand(float effectTime, float generateTime){
        _Dat += "AddNoteGenerateEffectHoldTrackExpand("
            + to_string(effectTime) + "f,"
            + to_string(generateTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Note Perfect判定效果（粒子），依附于Note
    /// </summary>
    /// <param name="particleObjectBundleName: 粒子的bundle的名字"></param>
    /// <param name="particleObjectName: 粒子物体的名字"></param>
    void AddNoteJudgePerfectEffectCreateParticles(string particleObjectBundleName, string particleObjectName){
        _Dat += "AddNoteJudgePerfectEffectCreateParticles("
            + particleObjectBundleName + ","
            + particleObjectName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 增加一个Note Miss判定效果（淡出），依附于Note
    /// </summary>
    /// <param name="effectTime  ">效果持续时间</param>
    void AddNoteJudgeMissEffectColorFade(float effectTime){
        _Dat += "AddNoteJudgeMissEffectColorFade(" + to_string(effectTime) + "f);";
        _Dat += _CRLF;
    }



    /// <summary>
    /// 生成一个Movement动画，移动物体，依附于所有实体物体（模型，Note）和PathNode
    /// </summary>
    /// <param name="trackStartTime  ">开始时间</param>
    /// <param name="trackEndTime  ">结束时间</param>
    /// <param name="trackSpaceType  ">轨道空间类型</param>
    /// <param name="isClosed  ">是否闭合</param>
    /// <param name="movementNodePositions  ">轨道点的集合</param>
    /// <param name="movementPercent  ">在Movement轨道上的百分比的动画（比如从0到0.5即从开头到中点）</param>
    /// <returns></returns>
    UReturn GenerateMovement(float trackStartTime, float trackEndTime, _TrackSpaceType trackSpaceType, bool _isClosed, Vector3List movementNodePositions, FlexibleFloat movementPercent){
        string isClosed;
        if (_isClosed) {
            isClosed = "true";
        }
        else {
            isClosed = "false";
        }

        _Dat += "GenerateMovement(" 
            + to_string(trackStartTime) + "f,"
            + to_string(trackStartTime) + "f"
            + trackSpaceType+","
            + isClosed+","
            + movementNodePositions.data()+","
            + movementPercent.data()+");"
            ;
        _Dat += _CRLF;
    }

    /// <summary>
    /// 生成一个Swirl动画，旋转物体，依附于所有实体物体（模型，Note）
    /// </summary>
    /// <param name="swirlX  ">欧拉角X轴动画</param>
    /// <param name="swirlY  ">欧拉角Y轴动画</param>
    /// <param name="swirlZ  ">欧拉角Z轴动画</param>
    /// <returns></returns>
    UReturn GenerateSwirl(FlexibleFloat swirlX, FlexibleFloat swirlY, FlexibleFloat swirlZ){
        _Dat += "GenerateSwirl(" + swirlX.data() + "," + swirlY.data() + "," + swirlZ.data()+ ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 生成一个Scale动画，缩放物体，依附于所有实体物体（模型，Note）
    /// </summary>
    /// <param name="scaleX  ">缩放X轴动画</param>
    /// <param name="scaleY  ">缩放Y轴动画</param>
    /// <param name="scaleZ  ">缩放Z轴动画</param>
    /// <returns></returns>
    UReturn GenerateScale(FlexibleFloat scaleX, FlexibleFloat scaleY, FlexibleFloat scaleZ){
        _Dat += "GenerateScale(" + scaleX.data() + "," + scaleY.data() + "," + scaleZ.data() + ");";
        _Dat += _CRLF;
    }

#pragma endregion

public:

public:
    string getFileAllContent()const {
        ifstream f(_Fip);
        if (!f) {
            return ("无法获取" + _Fip, "的内容 >> 打开失败！");
        }
        string s(std::istreambuf_iterator<char>(f), {});
        f.close();
        return s;
    }
    bool create()const {
        if (exist()) {
            return true;
        }
        fstream file;
        file.open(_Fip, ios::out);
        if (!file) {
            return false;
        }
        file.close();
        return true;
    }
	bool export2File()const {
        if (exist()) {
            empty();
        }
        else {
            create();
        }
        fstream wt(_Fip);
        if (!wt) {
            return false;
        }
        wt << _Dat;
        wt.close();
        return true;
	}
	void empty()const {
		fstream file(_Fip.data(), ios::out);
		file.close();
	}
	bool exist()const {
		ifstream f(_Fip.data());
		return f.good();
	}
	string data()const {
        if (!export2File()) {
            return "Error!";
        }
		return getFileAllContent();
	}
    string getFip()const {
        return _Fip;
    }
    string getDat()const {
        return _Dat;
    }
    void setFip(const string& Fip) {
        _Fip = Fip;
    }
    void setDat(const string& Dat) {
        _Dat = Dat;
    }
private:
	string _Fip;
	string _Dat;
};

