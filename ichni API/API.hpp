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
    /// ����һ����ϷԪ���ļ��У�Element Folder�������ܻ�������Track Group������һ����ͬ����ִ��֮ǰ�����е���ϷԪ�أ���Ҫ��Track�����ᱻ����ĺ������ɵ��ļ�����
    /// </summary>
	void GenerateElementFolder(){
        _Dat += "GenerateElementFolder();";
        _Dat += _CRLF;
	}

    /// <summary>
    /// ����һ���������������Element Folder���Ҹ�Element Folderֻ����Track
    /// </summary>
    /// <param name="cameraViewType: �����������͸�������3D���������������2D��"></param>
    /// <param name="viewAngleOrSize: �����͸��������趨������Ƕ�(0,180)�����������������趨���ӿڴ�С(0,������)"></param>
    /// <returns></returns>
    UReturn GenerateGameCamera(CameraViewType cameraViewType, float viewAngleOrSize){
        _Dat += "GenerateElementFolder();";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ��������м�������ǶȻ��ӿڴ�С�Ķ����������������
    /// </summary>
    /// <param name="view: Flexible Float����"></param>
    void ModifyGameCameraView(FlexibleFloat view){

    }

    /// <summary>
    /// ����һ��Track��������Element Folder
    /// </summary>
    /// <param name="trackStartTime: �����ʼʱ��"></param>
    /// <param name="trackEndTime: �������ʱ��"></param>
    /// <param name="trackCurve: ������еĶ�������"></param>
    /// <param name="trackMoveType: ����������ͣ�quiescentΪNote��β���ƶ���ͷ����movableΪNote�̶������ƶ���Note��ײ"></param>
    /// <param name="trackCauculateType: ����������ͣ�timeΪʱ�䣬distanceΪ���룬Ӱ������visibleTrack(Time/Length)"></param>
    /// <param name="trackSpaceType: ����ռ乹�����ͣ�Linear�߶Σ�CatmullRom���ߣ�BSplineƽ������"></param>
    /// <param name="visibleTrackLength: �ɼ��Ĺ�����ȣ����ܿ����Ĺ���Ĳ�����visibleTrackLength��ʱ��/���볤��"></param>
    /// <param name="isClosed: �Ƿ�պϣ���Ҫ����4��PathNode�ſ�����Ϊtrue"></param>
    /// <returns></returns>
    UReturn GenerateTrack(float trackStartTime, float trackEndTime, EaseCurve trackCurve, TrackMoveType trackMoveType, TrackCauculateType trackCauculateType,
        TrackSpaceType trackSpaceType, float visibleTrackLength, bool isClosed){

    }

    /// <summary>
    /// ���������һ�������ӡ�����ɫ������������Track
    /// </summary>
    /// <param name="flexibleColorModifierUnits�����ע��"></param>
    /// <returns></returns>
    //UReturn GenerateTrackColorModifier(List<FlexibleColorModifierUnit> flexibleColorModifierUnits){
    //
    //}

    /// <summary>
    /// �趨Track�Ĳ��ʣ�������Track
    /// </summary>
    /// <param name="texture"></param>
    void SetTrackTexture(string trackTextureBundleName, string trackTextureName){

    }

    /// <summary>
    /// �趨Track��һ���Ƿ��Զ������������������Track��Ĭ�Ͽ�����
    /// </summary>
    /// <param name="auto"></param>
    void SetTrackAutoOrient(bool _auto){

    }

    /// <summary>
    /// ��������������趨һ��������������Track
    /// </summary>
    /// <param name="width"></param>
    void ModifyGlobalTrackWidth(FlexibleFloat width){

    }

    /// <summary>
    /// �������������ɫ�趨һ��������������Track
    /// </summary>
    /// <param name="colorR"></param>
    /// <param name="colorG"></param>
    /// <param name="colorB"></param>
    /// <param name="colorA"></param>
    void ModifyGlobalTrackColor(FlexibleFloat colorR, FlexibleFloat colorG, FlexibleFloat colorB, FlexibleFloat colorA){

    }


    /// <summary>
    /// ����һ��PathNode��������Track
    /// </summary>
    /// <param name="nodePosition: PathNode��λ��"></param>
    /// <param name="nodeNormal: PathNode�ķ���"></param>
    /// <param name="nodeSize: PathNode�������ʵ������Track��PathNode��ʱ�Ŀ��"></param>
    /// <returns></returns>
    UReturn GeneratePathNode(Vector3 nodePosition, Vector3 nodeNormal, float nodeSize){

    }



    /// <summary>
    /// ����һ��Tap Note��������Track
    /// </summary>
    /// <param name="exactJudgeTime: �ж�ʱ��"></param>
    /// <returns></returns>
    UReturn GenerateTap(float exactJudgeTime){

    }

    /// <summary>
    /// ����һ��Stay Node��������Track
    /// </summary>
    /// <param name="exactJudgeTime: �ж�ʱ��"></param>
    /// <returns></returns>
    UReturn GenerateStay(float exactJudgeTime){

    }


    /// <summary>
    /// ����һ��Hold Note��������Track��ע�⣬Hold Note��ʱ���ȱ����Ǳ���������Track���Ӽ���
    /// </summary>
    /// <param name="exactJudgeTime: �ж�ʱ�䣨��㣩"></param>
    /// <param name="holdTime: ��Ҫ��ס��ʱ��"></param>
    /// <returns></returns>
    UReturn GenerateHold(float exactJudgeTime, float holdTime){

    }

    /// <summary>
    /// �趨Note�����Σ�������Note
    /// </summary>
    /// <param name="noteVisualObjectBundleName: ģ�ͻ����ӵ�bundle������"></param>
    /// <param name="noteVisualObjectName: ģ�ͻ����ӵ�����"></param>
    void SetNoteVisual(string noteVisualObjectBundleName, string noteVisualObjectName){

    }

    /// <summary>
    /// �趨Hold Note��ָʾ�㣨��Track��ͷ����λ��һ�£������Σ�������Hold Note
    /// </summary>
    /// <param name="holdHeadPointerBundleName"></param>
    /// <param name="holdHeadPointerName"></param>
    void SetHoldHeadPointer(string holdHeadPointerBundleName, string holdHeadPointerName){

    }

    /// <summary>
    /// �趨Hold Note��Track��һ���Ƿ��Զ������������������Hold Note
    /// </summary>
    /// <param name="auto"></param>
    void SetHoldTrackAutoOrient(bool auto){

    }

    /// <summary>
    /// ����һ��Note����Ч������������������Note
    /// </summary>
    /// <param name="generateTime"></param>
    void AddNoteGenerateEffectBase(float generateTime){

    }

    /// <summary>
    /// ����һ��Note����Ч�������ӣ���������Note
    /// </summary>
    /// <param name="particleObjectBundleName: ���ӵ�bundle������"></param>
    /// <param name="particleObjectName: �������������"></param>
    /// <param name="generateTime: ����ʱ�䣬����Note�ж�ʱ��(exactJudgeTime)��generateTime��ǰ�������Ч����ͬʱNote����"></param>
    void AddNoteGenerateEffectCreateParticles(string particleObjectBundleName, string particleObjectName, float generateTime){

    }

    /// <summary>
    /// ����һ��Hold Note����Ч�������죩���������effectTime��������չ���յ㣬������Hold Note
    /// </summary>
    /// <param name="effectTime: Ч������ʱ��"></param>
    /// <param name="generateTime: ����ʱ��"></param>
    void AddNoteGenerateEffectHoldTrackExpand(float effectTime, float generateTime){

    }

    /// <summary>
    /// ����һ��Note Perfect�ж�Ч�������ӣ���������Note
    /// </summary>
    /// <param name="particleObjectBundleName: ���ӵ�bundle������"></param>
    /// <param name="particleObjectName: �������������"></param>
    void AddNoteJudgePerfectEffectCreateParticles(string particleObjectBundleName, string particleObjectName){

    }

    /// <summary>
    /// ����һ��Note Miss�ж�Ч������������������Note
    /// </summary>
    /// <param name="effectTime: Ч������ʱ��"></param>
    void AddNoteJudgeMissEffectColorFade(float effectTime){

    }



    /// <summary>
    /// ����һ��Movement�������ƶ����壬����������ʵ�����壨ģ�ͣ�Note����PathNode
    /// </summary>
    /// <param name="trackStartTime: ��ʼʱ��"></param>
    /// <param name="trackEndTime: ����ʱ��"></param>
    /// <param name="trackSpaceType: ����ռ�����"></param>
    /// <param name="isClosed: �Ƿ�պ�"></param>
    /// <param name="movementNodePositions: �����ļ���"></param>
    /// <param name="movementPercent: ��Movement����ϵİٷֱȵĶ����������0��0.5���ӿ�ͷ���е㣩"></param>
    /// <returns></returns>
    //UReturn GenerateMovement(float trackStartTime, float trackEndTime, TrackSpaceType trackSpaceType, bool isClosed, List<Vector3> movementNodePositions, FlexibleFloat movementPercent){
    //
    //}

    /// <summary>
    /// ����һ��Swirl��������ת���壬����������ʵ�����壨ģ�ͣ�Note��
    /// </summary>
    /// <param name="swirlX: ŷ����X�ᶯ��"></param>
    /// <param name="swirlY: ŷ����Y�ᶯ��"></param>
    /// <param name="swirlZ: ŷ����Z�ᶯ��"></param>
    /// <returns></returns>
    UReturn GenerateSwirl(FlexibleFloat swirlX, FlexibleFloat swirlY, FlexibleFloat swirlZ){

    }

    /// <summary>
    /// ����һ��Scale�������������壬����������ʵ�����壨ģ�ͣ�Note��
    /// </summary>
    /// <param name="scaleX������X�ᶯ��"></param>
    /// <param name="scaleY������Y�ᶯ��"></param>
    /// <param name="scaleZ������Z�ᶯ��"></param>
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

