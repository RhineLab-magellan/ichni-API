/*
* �����ߣ���¶¶
* ����ʱ�䣺2022.2.3
* ������API�࣬�ṩ��������API
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

#pragma region �����ƺ������API����
    /// <summary>
    /// ����һ����ϷԪ���ļ��У�Element Folder�������ܻ�������Track Group������һ����ͬ����ִ��֮ǰ�����е���ϷԪ�أ���Ҫ��Track�����ᱻ����ĺ������ɵ��ļ�����
    /// </summary>
    void folder() {
        _Dat += "GenerateElementFolder();";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ���������������Element Folder���Ҹ�Element Folderֻ����Track
    /// </summary>
    /// <param name="cameraViewType: �����������͸�������3D���������������2D��"></param>
    /// <param name="viewAngleOrSize: �����͸��������趨������Ƕ�(0,180)�����������������趨���ӿڴ�С(0,������)"></param>
    /// <returns></returns>
    UReturn camera(_CameraViewType cameraViewType, float viewAngleOrSize) {
        _Dat += "GenerateGameCamera(" + cameraViewType + string(",") + to_string(viewAngleOrSize) + string("f);");
        _Dat += _CRLF;
    }

    /// <summary>
    /// ��������м�������ǶȻ��ӿڴ�С�Ķ����������������
    /// </summary>
    /// <param name="view: Flexible Float����"></param>
    void cameraView(FlexibleFloat view) {
        _Dat += "ModifyGameCameraView("
            + view.data()
            + ");";
        _Dat += _CRLF;
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
    /// ���������һ�������ӡ�����ɫ������������Track
    /// </summary>
    /// <param name="flexibleColorModifierUnits�����ע��"></param>
    /// <returns></returns>
    UReturn trackColor(FlexibleColorModifierUnitList flexibleColorModifierUnits) {

    }

    /// <summary>
    /// �趨Track�Ĳ��ʣ�������Track
    /// </summary>
    /// <param name="texture"></param>
    void trackTexture(string trackTextureBundleName, string trackTextureName) {
        _Dat += "SetTrackTexture(" + trackTextureBundleName + ", " + trackTextureName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// �趨Track��һ���Ƿ��Զ������������������Track��Ĭ�Ͽ�����
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
    /// ��������������趨һ��������������Track
    /// </summary>
    /// <param name="width"></param>
    void trackWidth(FlexibleFloat width) {
        _Dat += "ModifyGlobalTrackWidth(" + width.data() + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// �������������ɫ�趨һ��������������Track
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
    /// ����һ��PathNode��������Track
    /// </summary>
    /// <param name="nodePosition: PathNode��λ��"></param>
    /// <param name="nodeNormal: PathNode�ķ���"></param>
    /// <param name="nodeSize: PathNode�������ʵ������Track��PathNode��ʱ�Ŀ��"></param>
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
    /// ����һ��Tap Note��������Track
    /// </summary>
    /// <param name="exactJudgeTime  ">�ж�ʱ��</param>
    /// <returns></returns>
    UReturn tap(float exactJudgeTime) {
        _Dat += "GenerateTap(" + to_string(exactJudgeTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Stay Node��������Track
    /// </summary>
    /// <param name="exactJudgeTime  ">�ж�ʱ��</param>
    /// <returns></returns>
    UReturn stay(float exactJudgeTime) {
        _Dat += "GenerateStay(" + to_string(exactJudgeTime) + "f);";
        _Dat += _CRLF;
    }


    /// <summary>
    /// ����һ��Hold Note��������Track��ע�⣬Hold Note��ʱ���ȱ����Ǳ���������Track���Ӽ���
    /// </summary>
    /// <param name="exactJudgeTime  ">�ж�ʱ�䣨��㣩</param>
    /// <param name="holdTime  ">��Ҫ��ס��ʱ��</param>
    /// <returns></returns>
    UReturn hold(float exactJudgeTime, float holdTime) {
        _Dat += "GenerateHold("
            + to_string(exactJudgeTime) + "f,"
            + to_string(holdTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// �趨Note�����Σ�������Note
    /// </summary>
    /// <param name="noteVisualObjectBundleName  ">ģ�ͻ����ӵ�bundle������</param>
    /// <param name="noteVisualObjectName  ">ģ�ͻ����ӵ�����</param>
    void noteVisual(string noteVisualObjectBundleName, string noteVisualObjectName) {
        _Dat += "SetNoteVisual("
            + noteVisualObjectBundleName + ","
            + noteVisualObjectName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// �趨Hold Note��ָʾ�㣨��Track��ͷ����λ��һ�£������Σ�������Hold Note
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
    /// �趨Hold Note��Track��һ���Ƿ��Զ������������������Hold Note
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
    /// ����һ��Note����Ч������������������Note
    /// </summary>
    /// <param name="generateTime"></param>
    void addEffectBase(float generateTime) {
        _Dat += "AddNoteGenerateEffectBase(" + to_string(generateTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Note����Ч�������ӣ���������Note
    /// </summary>
    /// <param name="particleObjectBundleName: ���ӵ�bundle������"></param>
    /// <param name="particleObjectName: �������������"></param>
    /// <param name="generateTime: ����ʱ�䣬����Note�ж�ʱ��(exactJudgeTime)��generateTime��ǰ�������Ч����ͬʱNote����"></param>
    void addEffectCreateParticles(string particleObjectBundleName, string particleObjectName, float generateTime) {
        _Dat += "AddNoteGenerateEffectCreateParticles("
            + particleObjectBundleName + ","
            + particleObjectName + ","
            + to_string(generateTime)
            + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Hold Note����Ч�������죩���������effectTime��������չ���յ㣬������Hold Note
    /// </summary>
    /// <param name="effectTime: Ч������ʱ��"></param>
    /// <param name="generateTime: ����ʱ��"></param>
    void addEffectHoldTrackExpand(float effectTime, float generateTime) {
        _Dat += "AddNoteGenerateEffectHoldTrackExpand("
            + to_string(effectTime) + "f,"
            + to_string(generateTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Note Perfect�ж�Ч�������ӣ���������Note
    /// </summary>
    /// <param name="particleObjectBundleName: ���ӵ�bundle������"></param>
    /// <param name="particleObjectName: �������������"></param>
    void addPerfectEffectCreateParticles(string particleObjectBundleName, string particleObjectName) {
        _Dat += "AddNoteJudgePerfectEffectCreateParticles("
            + particleObjectBundleName + ","
            + particleObjectName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Note Miss�ж�Ч������������������Note
    /// </summary>
    /// <param name="effectTime  ">Ч������ʱ��</param>
    void addMissEffectColorFade(float effectTime) {
        _Dat += "AddNoteJudgeMissEffectColorFade(" + to_string(effectTime) + "f);";
        _Dat += _CRLF;
    }



    /// <summary>
    /// ����һ��Movement�������ƶ����壬����������ʵ�����壨ģ�ͣ�Note����PathNode
    /// </summary>
    /// <param name="trackStartTime  ">��ʼʱ��</param>
    /// <param name="trackEndTime  ">����ʱ��</param>
    /// <param name="trackSpaceType  ">����ռ�����</param>
    /// <param name="isClosed  ">�Ƿ�պ�</param>
    /// <param name="movementNodePositions  ">�����ļ���</param>
    /// <param name="movementPercent  ">��Movement����ϵİٷֱȵĶ����������0��0.5���ӿ�ͷ���е㣩</param>
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
    /// ����һ��Swirl��������ת���壬����������ʵ�����壨ģ�ͣ�Note��
    /// </summary>
    /// <param name="swirlX  ">ŷ����X�ᶯ��</param>
    /// <param name="swirlY  ">ŷ����Y�ᶯ��</param>
    /// <param name="swirlZ  ">ŷ����Z�ᶯ��</param>
    /// <returns></returns>
    UReturn swirl(FlexibleFloat swirlX, FlexibleFloat swirlY, FlexibleFloat swirlZ) {
        _Dat += "GenerateSwirl(" + swirlX.data() + "," + swirlY.data() + "," + swirlZ.data() + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Scale�������������壬����������ʵ�����壨ģ�ͣ�Note��
    /// </summary>
    /// <param name="scaleX  ">����X�ᶯ��</param>
    /// <param name="scaleY  ">����Y�ᶯ��</param>
    /// <param name="scaleZ  ">����Z�ᶯ��</param>
    /// <returns></returns>
    UReturn scale(FlexibleFloat scaleX, FlexibleFloat scaleY, FlexibleFloat scaleZ) {
        _Dat += "GenerateScale(" + scaleX.data() + "," + scaleY.data() + "," + scaleZ.data() + ");";
        _Dat += _CRLF;
    }

#pragma endregion

#pragma region ԭ����API����
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
    UReturn GenerateGameCamera(_CameraViewType cameraViewType, float viewAngleOrSize){
        _Dat += "GenerateGameCamera(" + cameraViewType + string(",")+to_string(viewAngleOrSize)+string("f);");
        _Dat += _CRLF;
    }

    /// <summary>
    /// ��������м�������ǶȻ��ӿڴ�С�Ķ����������������
    /// </summary>
    /// <param name="view: Flexible Float����"></param>
    void ModifyGameCameraView(FlexibleFloat view){
        _Dat += "ModifyGameCameraView("
            + view.data()
            +");";
        _Dat += _CRLF;
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
    /// ���������һ�������ӡ�����ɫ������������Track
    /// </summary>
    /// <param name="flexibleColorModifierUnits�����ע��"></param>
    /// <returns></returns>
    UReturn GenerateTrackColorModifier(FlexibleColorModifierUnitList flexibleColorModifierUnits) {

    }

    /// <summary>
    /// �趨Track�Ĳ��ʣ�������Track
    /// </summary>
    /// <param name="texture"></param>
    void SetTrackTexture(string trackTextureBundleName, string trackTextureName) {
        _Dat += "SetTrackTexture("+ trackTextureBundleName +", "+ trackTextureName +");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// �趨Track��һ���Ƿ��Զ������������������Track��Ĭ�Ͽ�����
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
    /// ��������������趨һ��������������Track
    /// </summary>
    /// <param name="width"></param>
    void ModifyGlobalTrackWidth(FlexibleFloat width){
        _Dat += "ModifyGlobalTrackWidth(" + width.data() + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// �������������ɫ�趨һ��������������Track
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
    /// ����һ��PathNode��������Track
    /// </summary>
    /// <param name="nodePosition: PathNode��λ��"></param>
    /// <param name="nodeNormal: PathNode�ķ���"></param>
    /// <param name="nodeSize: PathNode�������ʵ������Track��PathNode��ʱ�Ŀ��"></param>
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
    /// ����һ��Tap Note��������Track
    /// </summary>
    /// <param name="exactJudgeTime  ">�ж�ʱ��</param>
    /// <returns></returns>
    UReturn GenerateTap(float exactJudgeTime){
        _Dat += "GenerateTap(" + to_string(exactJudgeTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Stay Node��������Track
    /// </summary>
    /// <param name="exactJudgeTime  ">�ж�ʱ��</param>
    /// <returns></returns>
    UReturn GenerateStay(float exactJudgeTime){
        _Dat += "GenerateStay(" + to_string(exactJudgeTime) + "f);";
        _Dat += _CRLF;
    }


    /// <summary>
    /// ����һ��Hold Note��������Track��ע�⣬Hold Note��ʱ���ȱ����Ǳ���������Track���Ӽ���
    /// </summary>
    /// <param name="exactJudgeTime  ">�ж�ʱ�䣨��㣩</param>
    /// <param name="holdTime  ">��Ҫ��ס��ʱ��</param>
    /// <returns></returns>
    UReturn GenerateHold(float exactJudgeTime, float holdTime){
        _Dat += "GenerateHold(" 
            + to_string(exactJudgeTime) + "f,"
            + to_string(holdTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// �趨Note�����Σ�������Note
    /// </summary>
    /// <param name="noteVisualObjectBundleName  ">ģ�ͻ����ӵ�bundle������</param>
    /// <param name="noteVisualObjectName  ">ģ�ͻ����ӵ�����</param>
    void SetNoteVisual(string noteVisualObjectBundleName, string noteVisualObjectName){
        _Dat += "SetNoteVisual("
            + noteVisualObjectBundleName + ","
            + noteVisualObjectName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// �趨Hold Note��ָʾ�㣨��Track��ͷ����λ��һ�£������Σ�������Hold Note
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
    /// �趨Hold Note��Track��һ���Ƿ��Զ������������������Hold Note
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
    /// ����һ��Note����Ч������������������Note
    /// </summary>
    /// <param name="generateTime"></param>
    void AddNoteGenerateEffectBase(float generateTime){
        _Dat += "AddNoteGenerateEffectBase(" + to_string(generateTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Note����Ч�������ӣ���������Note
    /// </summary>
    /// <param name="particleObjectBundleName: ���ӵ�bundle������"></param>
    /// <param name="particleObjectName: �������������"></param>
    /// <param name="generateTime: ����ʱ�䣬����Note�ж�ʱ��(exactJudgeTime)��generateTime��ǰ�������Ч����ͬʱNote����"></param>
    void AddNoteGenerateEffectCreateParticles(string particleObjectBundleName, string particleObjectName, float generateTime){
        _Dat += "AddNoteGenerateEffectCreateParticles("
            + particleObjectBundleName + ","
            + particleObjectName +","
            + to_string(generateTime)
            + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Hold Note����Ч�������죩���������effectTime��������չ���յ㣬������Hold Note
    /// </summary>
    /// <param name="effectTime: Ч������ʱ��"></param>
    /// <param name="generateTime: ����ʱ��"></param>
    void AddNoteGenerateEffectHoldTrackExpand(float effectTime, float generateTime){
        _Dat += "AddNoteGenerateEffectHoldTrackExpand("
            + to_string(effectTime) + "f,"
            + to_string(generateTime) + "f);";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Note Perfect�ж�Ч�������ӣ���������Note
    /// </summary>
    /// <param name="particleObjectBundleName: ���ӵ�bundle������"></param>
    /// <param name="particleObjectName: �������������"></param>
    void AddNoteJudgePerfectEffectCreateParticles(string particleObjectBundleName, string particleObjectName){
        _Dat += "AddNoteJudgePerfectEffectCreateParticles("
            + particleObjectBundleName + ","
            + particleObjectName + ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Note Miss�ж�Ч������������������Note
    /// </summary>
    /// <param name="effectTime  ">Ч������ʱ��</param>
    void AddNoteJudgeMissEffectColorFade(float effectTime){
        _Dat += "AddNoteJudgeMissEffectColorFade(" + to_string(effectTime) + "f);";
        _Dat += _CRLF;
    }



    /// <summary>
    /// ����һ��Movement�������ƶ����壬����������ʵ�����壨ģ�ͣ�Note����PathNode
    /// </summary>
    /// <param name="trackStartTime  ">��ʼʱ��</param>
    /// <param name="trackEndTime  ">����ʱ��</param>
    /// <param name="trackSpaceType  ">����ռ�����</param>
    /// <param name="isClosed  ">�Ƿ�պ�</param>
    /// <param name="movementNodePositions  ">�����ļ���</param>
    /// <param name="movementPercent  ">��Movement����ϵİٷֱȵĶ����������0��0.5���ӿ�ͷ���е㣩</param>
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
    /// ����һ��Swirl��������ת���壬����������ʵ�����壨ģ�ͣ�Note��
    /// </summary>
    /// <param name="swirlX  ">ŷ����X�ᶯ��</param>
    /// <param name="swirlY  ">ŷ����Y�ᶯ��</param>
    /// <param name="swirlZ  ">ŷ����Z�ᶯ��</param>
    /// <returns></returns>
    UReturn GenerateSwirl(FlexibleFloat swirlX, FlexibleFloat swirlY, FlexibleFloat swirlZ){
        _Dat += "GenerateSwirl(" + swirlX.data() + "," + swirlY.data() + "," + swirlZ.data()+ ");";
        _Dat += _CRLF;
    }

    /// <summary>
    /// ����һ��Scale�������������壬����������ʵ�����壨ģ�ͣ�Note��
    /// </summary>
    /// <param name="scaleX  ">����X�ᶯ��</param>
    /// <param name="scaleY  ">����Y�ᶯ��</param>
    /// <param name="scaleZ  ">����Z�ᶯ��</param>
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
            return ("�޷���ȡ" + _Fip, "������ >> ��ʧ�ܣ�");
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

