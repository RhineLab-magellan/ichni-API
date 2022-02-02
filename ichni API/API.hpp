#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "type.hpp"
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ios;

#define _CRLF "\r\n"

class API
{
public:
	API(string filePath):_Dat("") {
		_Fip = filePath;
	}
	~API(){}
public:
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
    UReturn GenerateGameCamera(CameraViewType cameraViewType, float viewAngleOrSize){
        _Dat += "GenerateElementFolder();";
        _Dat += _CRLF;
    }

    /// <summary>
    /// 在摄像机中加入拍摄角度或视口大小的动画，依附于摄像机
    /// </summary>
    /// <param name="view: Flexible Float动画"></param>
    void ModifyGameCameraView(FlexibleFloat view){

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
    UReturn GenerateTrack(float trackStartTime, float trackEndTime, EaseCurve trackCurve, TrackMoveType trackMoveType, TrackCauculateType trackCauculateType,
        TrackSpaceType trackSpaceType, float visibleTrackLength, bool isClosed){

    }

    /// <summary>
    /// 给轨道增加一个“复杂”的颜色修正，依附于Track
    /// </summary>
    /// <param name="flexibleColorModifierUnits：详见注解"></param>
    /// <returns></returns>
    //UReturn GenerateTrackColorModifier(List<FlexibleColorModifierUnit> flexibleColorModifierUnits){
    //
    //}

    /// <summary>
    /// 设定Track的材质，依附于Track
    /// </summary>
    /// <param name="texture"></param>
    void SetTrackTexture(string trackTextureBundleName, string trackTextureName){

    }

    /// <summary>
    /// 设定Track的一面是否自动对着摄像机，依附于Track（默认开启）
    /// </summary>
    /// <param name="auto"></param>
    void SetTrackAutoOrient(bool _auto){

    }

    /// <summary>
    /// 给轨道的总体宽度设定一个动画，依附于Track
    /// </summary>
    /// <param name="width"></param>
    void ModifyGlobalTrackWidth(FlexibleFloat width){

    }

    /// <summary>
    /// 给轨道的总体颜色设定一个动画，依附于Track
    /// </summary>
    /// <param name="colorR"></param>
    /// <param name="colorG"></param>
    /// <param name="colorB"></param>
    /// <param name="colorA"></param>
    void ModifyGlobalTrackColor(FlexibleFloat colorR, FlexibleFloat colorG, FlexibleFloat colorB, FlexibleFloat colorA){

    }


    /// <summary>
    /// 创建一个PathNode，依附于Track
    /// </summary>
    /// <param name="nodePosition: PathNode的位置"></param>
    /// <param name="nodeNormal: PathNode的法线"></param>
    /// <param name="nodeSize: PathNode的体积，实际上是Track在PathNode点时的宽度"></param>
    /// <returns></returns>
    UReturn GeneratePathNode(Vector3 nodePosition, Vector3 nodeNormal, float nodeSize){

    }



    /// <summary>
    /// 创建一个Tap Note，依附于Track
    /// </summary>
    /// <param name="exactJudgeTime: 判定时间"></param>
    /// <returns></returns>
    UReturn GenerateTap(float exactJudgeTime){

    }

    /// <summary>
    /// 创建一个Stay Node，依附于Track
    /// </summary>
    /// <param name="exactJudgeTime: 判定时间"></param>
    /// <returns></returns>
    UReturn GenerateStay(float exactJudgeTime){

    }


    /// <summary>
    /// 创建一个Hold Note，依附于Track，注意，Hold Note的时间跨度必须是被其依附的Track的子集！
    /// </summary>
    /// <param name="exactJudgeTime: 判定时间（起点）"></param>
    /// <param name="holdTime: 需要按住的时间"></param>
    /// <returns></returns>
    UReturn GenerateHold(float exactJudgeTime, float holdTime){

    }

    /// <summary>
    /// 设定Note的外形，依附于Note
    /// </summary>
    /// <param name="noteVisualObjectBundleName: 模型或粒子的bundle的名字"></param>
    /// <param name="noteVisualObjectName: 模型或粒子的名字"></param>
    void SetNoteVisual(string noteVisualObjectBundleName, string noteVisualObjectName){

    }

    /// <summary>
    /// 设定Hold Note里指示点（和Track的头部的位置一致）的外形，依附于Hold Note
    /// </summary>
    /// <param name="holdHeadPointerBundleName"></param>
    /// <param name="holdHeadPointerName"></param>
    void SetHoldHeadPointer(string holdHeadPointerBundleName, string holdHeadPointerName){

    }

    /// <summary>
    /// 设定Hold Note的Track的一面是否自动对着摄像机，依附于Hold Note
    /// </summary>
    /// <param name="auto"></param>
    void SetHoldTrackAutoOrient(bool auto){

    }

    /// <summary>
    /// 增加一个Note生成效果（基础），依附于Note
    /// </summary>
    /// <param name="generateTime"></param>
    void AddNoteGenerateEffectBase(float generateTime){

    }

    /// <summary>
    /// 增加一个Note生成效果（粒子），依附于Note
    /// </summary>
    /// <param name="particleObjectBundleName: 粒子的bundle的名字"></param>
    /// <param name="particleObjectName: 粒子物体的名字"></param>
    /// <param name="generateTime: 生成时间，即在Note判定时间(exactJudgeTime)的generateTime秒前生成这个效果，同时Note出现"></param>
    void AddNoteGenerateEffectCreateParticles(string particleObjectBundleName, string particleObjectName, float generateTime){

    }

    /// <summary>
    /// 增加一个Hold Note生成效果（延伸），从起点在effectTime秒中逐渐扩展到终点，依附于Hold Note
    /// </summary>
    /// <param name="effectTime: 效果持续时间"></param>
    /// <param name="generateTime: 生成时间"></param>
    void AddNoteGenerateEffectHoldTrackExpand(float effectTime, float generateTime){

    }

    /// <summary>
    /// 增加一个Note Perfect判定效果（粒子），依附于Note
    /// </summary>
    /// <param name="particleObjectBundleName: 粒子的bundle的名字"></param>
    /// <param name="particleObjectName: 粒子物体的名字"></param>
    void AddNoteJudgePerfectEffectCreateParticles(string particleObjectBundleName, string particleObjectName){

    }

    /// <summary>
    /// 增加一个Note Miss判定效果（淡出），依附于Note
    /// </summary>
    /// <param name="effectTime: 效果持续时间"></param>
    void AddNoteJudgeMissEffectColorFade(float effectTime){

    }



    /// <summary>
    /// 生成一个Movement动画，移动物体，依附于所有实体物体（模型，Note）和PathNode
    /// </summary>
    /// <param name="trackStartTime: 开始时间"></param>
    /// <param name="trackEndTime: 结束时间"></param>
    /// <param name="trackSpaceType: 轨道空间类型"></param>
    /// <param name="isClosed: 是否闭合"></param>
    /// <param name="movementNodePositions: 轨道点的集合"></param>
    /// <param name="movementPercent: 在Movement轨道上的百分比的动画（比如从0到0.5即从开头到中点）"></param>
    /// <returns></returns>
    //UReturn GenerateMovement(float trackStartTime, float trackEndTime, TrackSpaceType trackSpaceType, bool isClosed, List<Vector3> movementNodePositions, FlexibleFloat movementPercent){
    //
    //}

    /// <summary>
    /// 生成一个Swirl动画，旋转物体，依附于所有实体物体（模型，Note）
    /// </summary>
    /// <param name="swirlX: 欧拉角X轴动画"></param>
    /// <param name="swirlY: 欧拉角Y轴动画"></param>
    /// <param name="swirlZ: 欧拉角Z轴动画"></param>
    /// <returns></returns>
    UReturn GenerateSwirl(FlexibleFloat swirlX, FlexibleFloat swirlY, FlexibleFloat swirlZ){

    }

    /// <summary>
    /// 生成一个Scale动画，缩放物体，依附于所有实体物体（模型，Note）
    /// </summary>
    /// <param name="scaleX：缩放X轴动画"></param>
    /// <param name="scaleY：缩放Y轴动画"></param>
    /// <param name="scaleZ：缩放Z轴动画"></param>
    /// <returns></returns>
    UReturn GenerateScale(FlexibleFloat scaleX, FlexibleFloat scaleY, FlexibleFloat scaleZ){

    }




public:

public:
	void export2File(string )const {
		fstream f(_Fip);
	}
	void empty() {
		fstream file(this->_Fip.data(), ios::out);
		file.close();
	}
	bool exist() {
		ifstream f(this->_Fip.data());
		return f.good();
	}
	string data()const {
		return _Dat;
	}

private:
	string _Fip;
	string _Dat;
};

