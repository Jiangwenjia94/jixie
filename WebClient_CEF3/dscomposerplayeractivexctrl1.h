#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装器类

// 注意:  不要修改此文件的内容。  如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CDscomposerplayeractivexctrl1 包装器类

class CDscomposerplayeractivexctrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CDscomposerplayeractivexctrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x410B702D, 0xFCFC, 0x46B7, { 0xA9, 0x54, 0xE8, 0x76, 0xC8, 0x4A, 0xE4, 0xC0 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
		UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
			pPersist, bStorage, bstrLicKey);
	}

	// 特性
public:
	enum
	{
		crRrmRenderFirst = 0,
		crRrmSmooth = 0,
		crRrmSmoothWithOutlines = 1,
		crRrmTechnical = 2,
		crRrmTechnicalFlat = 3,
		crRrmSilhouette = 4,
		crRrmFlat = 5,
		crRrmWireframe = 6,
		crRrmPoint = 7,
		crRrmShadedIllustration = 8,
		crRrmShadedIllustrationWithColors = 9,
		crRrmShadedIllustrationSimple = 10,
		crRrmCustomRendering = 11,
		crRrmRenderLast = 12
	}CrRender;
	enum
	{
		crRfsHighSpeedRefresh = 0,
		crRfsScene = 1,
		crRfsRefreshAntiAliasing = 2
	}CrRefreshType;
	enum
	{
		crAtvUndefinedValues = 0,
		crAtvAllActors = 0,
		crAtvKeepActorVisibility = 0,
		crAtvVisible = 1,
		crAtvInvisible = 2,
		crAtvGhost = 3
	}CrActorVisibility;
	enum
	{
		crFlrNone = 0,
		crFlrAnnotations = 1,
		crFlrCuttingPlanes = 2,
		crFlrSave = 4,
		crFlrClashDetection = 8,
		crFlrAdvancedActiveX = 16,
		crFlrTrees = 32,
		crFlrSimulation = 64,
		crFlrLoadingOnDemand = 128,
		crFlrBOMs = 256,
		crFlrFreezePublication = 1024,
		crFlrForbidDeleteParts = 2048,
		crFlrCrossHighlight = 4096,
		crFlrAdvancedMetaProperties = 8192,
		crFlrForbidDeleteActors = 16384
	}CrFileRights;
	enum
	{
		crMptMetaPropertyTypeFirst = 0,
		crMptBoolean = 0,
		crMptInteger = 1,
		crMptFloating = 2,
		crMptString = 3,
		crMptDate = 4,
		crMptColor = 5,
		crMptMetaPropertyTypeLast = 6
	}CrMetaPropertyType;
	enum
	{
		crMpaAnimatable = 2,
		crMpaAnimable = 2,
		crMpaMergeable = 4,
		crMpaVisible = 8
	}CrMetaPropertyAttribute;
	enum
	{
		crMpuNone = 0,
		crMpuAcceleration = 1,
		crMpuAngle = 2,
		crMpuArea = 3,
		crMpuLength = 4,
		crMpuSpeed = 5,
		crMpuTime = 6,
		crMpuVolume = 7
	}CrMetaPropertyUnit;
	enum
	{
		crDgrOnionSkin = 0,
		crDgrOignonSkin = 0,
		crDgrXRay = 1,
		crDgrCuttingPlane = 2,
		crDgrZoom = 3
	}CrDiggerRender;
	enum
	{
		crLycDefaultSelection = 0,
		crLycAssy = 1,
		crLycHighlight = 2,
		crLycAssyHighlight = 3,
		crLycPMICrsHLSelection = 4,
		crLycPMICrsHLHighlight = 5
	}CrLayerColor;
	enum
	{
		crObjAssys = 1,
		crObjCADViews = 2,
		crObjCADCaptures = 4,
		crObjAllChildren = 7
	}CrObjectType;
	enum
	{
		crNavigationSelect = 0,
		crNavigationRotate = 1,
		crNavigationPan = 2,
		crNavigationZoom = 3,
		crNavigationFlyThrough = 4
	}CrMouseNavigation;
	enum
	{
		crClfNoCollaboration = 0,
		crClfAnnotation = 1,
		crClfCallout = 2,
		crClfCamera = 3,
		crClfCoordinateSystem = 4,
		crClfCuttingPlane = 5,
		crClfEnvironment = 6,
		crClfIntersectionLines = 7,
		crClfLighting = 8,
		crClfMagneticLine = 9,
		crClfMarkups = 10,
		crClfMeasurement = 11,
		crClfPanel = 12,
		crClfPaths = 13,
		crClfPMI = 14
	}CrCollaborationFamily;
	enum
	{
		crApplicationProfileStandard = 0,
		crApplicationProfileHighSpeed = 2,
		crApplicationProfileHighQuality = 3,
		crApplicationProfileSafe = 4
	}CrApplicationProfile;
	enum
	{
		crOdpNone = 0,
		crOdpRenderGroundShadow = 1,
		crOdpRenderMode = 2,
		crOdpGroundGrid = 4,
		crOdpAll = -1
	}CrOverloadedDocumentProperties;


	// 操作
public:

	// _DDSComposerPlayerActiveX

	// Functions
	//

	short Rotate(short nAngle)
	{
		short result;
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I2, (void*)&result, parms, nAngle);
		return result;
	}
	short RedrawScene()
	{
		short result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short ZoomAll()
	{
		short result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short ZoomIn()
	{
		short result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short ZoomOut()
	{
		short result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short PrintDrawing(BOOL ShowDialog)
	{
		short result;
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I2, (void*)&result, parms, ShowDialog);
		return result;
	}
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Play()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Stop()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Antialiasing()
	{
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ZoomFitAll()
	{
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ZoomSelection()
	{
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Undo()
	{
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Redo()
	{
		InvokeHelper(0x70, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL GoToConfiguration(LPCTSTR strConfigurationName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strConfigurationName);
		return result;
	}
	BOOL GoToMarker(LPCTSTR strMarkerName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x82, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strMarkerName);
		return result;
	}
	BOOL PlayMarkerSequence(LPCTSTR strMarkerName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x83, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strMarkerName);
		return result;
	}
	BOOL GoToLayer(LPCTSTR strLayerName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strLayerName);
		return result;
	}
	BOOL AddLink(LPCTSTR strSelection, LPCTSTR strLink, BOOL bAutoLink)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BOOL;
		InvokeHelper(0x86, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, strLink, bAutoLink);
		return result;
	}
	BOOL SetPropertyMap(LPCTSTR strPropertyMap)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPropertyMap);
		return result;
	}
	void RefreshScene(long RefreshType)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x88, DISPATCH_METHOD, VT_EMPTY, NULL, parms, RefreshType);
	}
	BOOL SetPropertySet(LPCTSTR strSelection, LPCTSTR strPropertySet)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x89, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, strPropertySet);
		return result;
	}
	void SetVisibility(LPCTSTR strSelection, long Visibility, long InvVisibility)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4;
		InvokeHelper(0x8b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSelection, Visibility, InvVisibility);
	}
	void InvertVisibility(BOOL bWithGhost)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x8c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bWithGhost);
	}
	void ShowNoShowCollaboration()
	{
		InvokeHelper(0x8d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Merge(LPCTSTR sFileName)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x8e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sFileName);
	}
	long GetOptionsPro()
	{
		long result;
		InvokeHelper(0x8f, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL SaveSMG(LPCTSTR strFilePath, LPCTSTR strPassword)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x94, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilePath, strPassword);
		return result;
	}
	BOOL SaveImage(LPCTSTR strPathName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x96, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPathName);
		return result;
	}
	BOOL SaveImageFullViewport(LPCTSTR strPathName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x10c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPathName);
		return result;
	}
	BOOL Remove(LPCTSTR strSelection)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x98, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL SelectOnFilter(LPCTSTR strPropertySet, BOOL bMatchValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL;
		InvokeHelper(0x9a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPropertySet, bMatchValue);
		return result;
	}
	CString GetLinks(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x9c, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	CString GetAllActors(long Visibility)
	{
		CString result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x9e, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Visibility);
		return result;
	}
	CString GetAllLinks()
	{
		CString result;
		InvokeHelper(0x9f, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetAllTexts()
	{
		CString result;
		InvokeHelper(0xa0, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetAllCollaborations()
	{
		CString result;
		InvokeHelper(0xa1, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetAllActorsOnFilter(LPCTSTR strPropertySet, BOOL bMatchValue)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL;
		InvokeHelper(0xa2, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strPropertySet, bMatchValue);
		return result;
	}
	CString GetAllConfigurations()
	{
		CString result;
		InvokeHelper(0xa3, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetAllMarkers()
	{
		CString result;
		InvokeHelper(0xa4, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long GetVisibility(LPCTSTR strSelection)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xa6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strSelection);
		return result;
	}
	CString GetProperties(LPCTSTR strSelection, BOOL bIntersect, BOOL bMatchValue)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_BOOL;
		InvokeHelper(0xa7, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection, bIntersect, bMatchValue);
		return result;
	}
	CString GetAllLayers()
	{
		CString result;
		InvokeHelper(0xa8, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void Pause()
	{
		InvokeHelper(0xa9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL RotateInWCS(LPCTSTR strSelection, float fOriginX, float fOriginY, float fOriginZ, float fVectorX, float fVectorY, float fVectorZ, float fAngle)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xac, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, fOriginX, fOriginY, fOriginZ, fVectorX, fVectorY, fVectorZ, fAngle);
		return result;
	}
	BOOL RotateInParent(LPCTSTR strSelection, float fOriginX, float fOriginY, float fOriginZ, float fVectorX, float fVectorY, float fVectorZ, float fAngle)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xad, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, fOriginX, fOriginY, fOriginZ, fVectorX, fVectorY, fVectorZ, fAngle);
		return result;
	}
	BOOL TranslateInWCS(LPCTSTR strSelection, float fTanslateX, float fTanslateY, float fTanslateZ)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xae, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, fTanslateX, fTanslateY, fTanslateZ);
		return result;
	}
	BOOL TranslateInParent(LPCTSTR strSelection, float fTanslateX, float fTanslateY, float fTanslateZ)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xaf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, fTanslateX, fTanslateY, fTanslateZ);
		return result;
	}
	BOOL TranslateInLCS(LPCTSTR strSelection, float fTranslateX, float fTranslateY, float fTranslateZ)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xb0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, fTranslateX, fTranslateY, fTranslateZ);
		return result;
	}
	BOOL RotateInLCS(LPCTSTR strSelection, float fOriginX, float fOriginY, float fOriginZ, float fVectorX, float fVectorY, float fVectorZ, float fAngle)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xb1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, fOriginX, fOriginY, fOriginZ, fVectorX, fVectorY, fVectorZ, fAngle);
		return result;
	}
	BOOL SetCamera(LPCTSTR strDefCamera)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xb3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strDefCamera);
		return result;
	}
	CString GetCamera()
	{
		CString result;
		InvokeHelper(0xb4, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetAssyRoot()
	{
		CString result;
		InvokeHelper(0xb7, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetAssyChild(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xb8, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	CString GetAssyParents(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xb9, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL IsPureAssy(LPCTSTR strSelection)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xba, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL HasChilds(LPCTSTR strSelection)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xbb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL SetViewport(LPCTSTR strDefViewport)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xbd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strDefViewport);
		return result;
	}
	CString GetViewport()
	{
		CString result;
		InvokeHelper(0xbe, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL SetDigger(LPCTSTR strDefDigger)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xbf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strDefDigger);
		return result;
	}
	CString GetDigger()
	{
		CString result;
		InvokeHelper(0xc0, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL AddProductIn(LPCTSTR strFilename, LPCTSTR strNetGuid)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xc4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilename, strNetGuid);
		return result;
	}
	void LaunchCommandMessage(LPCTSTR strCommandCode)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strCommandCode);
	}
	void PrintPreview()
	{
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Print()
	{
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void PrintSetup()
	{
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL AddMetaPropertyDefinition(LPCTSTR Name, long MetaType, LPCTSTR MetaLabel, long StateFlags, long Unit, BOOL Bounded, float MinValue, float MaxValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_BOOL VTS_R4 VTS_R4;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Name, MetaType, MetaLabel, StateFlags, Unit, Bounded, MinValue, MaxValue);
		return result;
	}
	BOOL RemoveMetaPropertyDefinition(LPCTSTR Name)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Name);
		return result;
	}
	BOOL AddMetaProperties(LPCTSTR strSelection, LPCTSTR strPropertySet)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, strPropertySet);
		return result;
	}
	BOOL RemoveMetaProperties(LPCTSTR strPropertyMap)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPropertyMap);
		return result;
	}
	BOOL SetRightsManagerOptions(LPCTSTR strVendorCode, long ulRights)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strVendorCode, ulRights);
		return result;
	}
	BOOL SetNeutralProperties(LPCTSTR strSelection, LPCTSTR strPropertySet)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, strPropertySet);
		return result;
	}
	BOOL RestoreNeutralProperties(LPCTSTR strSelection, LPCTSTR strPropertySet)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xd8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection, strPropertySet);
		return result;
	}
	CString GetPropertyValue(LPCTSTR strSelection, LPCTSTR strPropertyName)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xd9, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection, strPropertyName);
		return result;
	}
	BOOL SetDiggerRenderer(long DigRenderer)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xda, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DigRenderer);
		return result;
	}
	long GetDiggerRenderer()
	{
		long result;
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString GetInvertedSelection(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL SetColor(long LayerColor, long ulR, long ulG, long ulB)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, LayerColor, ulR, ulG, ulB);
		return result;
	}
	BOOL LaunchQueryBBox()
	{
		BOOL result;
		InvokeHelper(0xde, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	CString GetAllActorsByType(LPCTSTR strClassName)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strClassName);
		return result;
	}
	BOOL ExportAllViews(LPCTSTR strFilename)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xe0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilename);
		return result;
	}
	BOOL ExportViews(LPCTSTR strViewsSelection, LPCTSTR strFilename)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xe1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strViewsSelection, strFilename);
		return result;
	}
	BOOL ExportViewsPubs(LPCTSTR strViewsIDSelection, LPCTSTR strFilename)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xe2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strViewsIDSelection, strFilename);
		return result;
	}
	BOOL ExportAllPubs(LPCTSTR strFilename, long Visibility)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4;
		InvokeHelper(0xe3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilename, Visibility);
		return result;
	}
	BOOL ImportViewsData(LPCTSTR strFilename, LPCTSTR strViewIDInsertAfter)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xe4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilename, strViewIDInsertAfter);
		return result;
	}
	BOOL ImportPubs(LPCTSTR strFilename)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xe5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilename);
		return result;
	}
	BOOL RemoveViews(LPCTSTR strViewsIDSelection)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xe6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strViewsIDSelection);
		return result;
	}
	BOOL UpdateView(LPCTSTR strViewID)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xe7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strViewID);
		return result;
	}
	BOOL AddProductIn2(LPCTSTR strFilename, LPCTSTR strNetGuidToAttach, LPCTSTR strInstanceGuid)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xe8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilename, strNetGuidToAttach, strInstanceGuid);
		return result;
	}
	BOOL RemoveProductNodes(LPCTSTR strSelection)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xe9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL AbortQueries()
	{
		BOOL result;
		InvokeHelper(0xea, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL IsCollaboration(LPCTSTR Selection)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xf3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Selection);
		return result;
	}
	CString GetCADCaptures()
	{
		CString result;
		InvokeHelper(0xf4, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetCADViews()
	{
		CString result;
		InvokeHelper(0xf5, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetAllViews()
	{
		CString result;
		InvokeHelper(0xf6, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetChildren(LPCTSTR Selection, long mask)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4;
		InvokeHelper(0xf7, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Selection, mask);
		return result;
	}
	BOOL GoToView(LPCTSTR viewName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xf8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, viewName);
		return result;
	}
	CString GetChildrenView(LPCTSTR viewName)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xf9, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, viewName);
		return result;
	}
	CString CreateBBox(float fPtAx, float fPtAy, float fPtAz, float fPtBx, float fPtBy, float fPtBz)
	{
		CString result;
		static BYTE parms[] = VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xfa, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, fPtAx, fPtAy, fPtAz, fPtBx, fPtBy, fPtBz);
		return result;
	}
	CString GetOnFilter(LPCTSTR strPropertySet, BOOL bMatchValue)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL;
		InvokeHelper(0xfb, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strPropertySet, bMatchValue);
		return result;
	}
	CString CreateAssyGroup(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xfc, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	CString CreateDummyObject(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xfd, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	long ChangeParent(LPCTSTR strSelection, LPCTSTR strSelectionNewParent)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xfe, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strSelection, strSelectionNewParent);
		return result;
	}
	long ReplaceGeometry(LPCTSTR strFilename, LPCTSTR strNetGUIDSource, LPCTSTR strSelectionDest)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xff, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strFilename, strNetGUIDSource, strSelectionDest);
		return result;
	}
	long ExportResources(LPCTSTR strFolderName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x100, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strFolderName);
		return result;
	}
	CString GetLocationInWorld(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x101, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	CString GetLocationInParent(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x102, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	CString GetLocationInPart(LPCTSTR strSelectionSource, LPCTSTR strSelectionDest)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x103, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelectionSource, strSelectionDest);
		return result;
	}
	BOOL SetGround(LPCTSTR strDefGround)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x108, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strDefGround);
		return result;
	}
	CString GetGround()
	{
		CString result;
		InvokeHelper(0x109, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL SetCompass(LPCTSTR strDefCompass)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x106, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strDefCompass);
		return result;
	}
	CString GetCompass()
	{
		CString result;
		InvokeHelper(0x107, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long SetMouseNavigationMode(long NavigationType)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x10b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, NavigationType);
		return result;
	}
	CString GetAllMetaPropertyDefinitions()
	{
		CString result;
		InvokeHelper(0x10a, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetTempFolder()
	{
		CString result;
		InvokeHelper(0x10d, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void ScrollViewToTop(LPCTSTR strName)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x10f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strName);
	}
	long SelectViews(LPCTSTR strSelection)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x110, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strSelection);
		return result;
	}
	long GetFamily(LPCTSTR strSelection)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x111, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strSelection);
		return result;
	}
	CString GetActorsClassName(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x112, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL ImportViewsData2(LPCTSTR strFilename, LPCTSTR strViewIDInsertAfter, BOOL bForceResolution, BOOL bAllInstances)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BOOL VTS_BOOL;
		InvokeHelper(0x113, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilename, strViewIDInsertAfter, bForceResolution, bAllInstances);
		return result;
	}
	BOOL GetMeasurementPersistency()
	{
		BOOL result;
		InvokeHelper(0x119, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetMeasurementPersistency(BOOL bPersistency)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x11a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bPersistency);
	}
	long FilterViews(LPCTSTR strSelection)
	{
		long result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x11b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL IsPlayerPro()
	{
		BOOL result;
		InvokeHelper(0x115, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	CString GetVersion()
	{
		CString result;
		InvokeHelper(0x116, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetFileVersion()
	{
		CString result;
		InvokeHelper(0x117, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL SetAdvancedLicense(LPCTSTR strVendorCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x11c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strVendorCode);
		return result;
	}
	CString GetActorsProperties(LPCTSTR strSelection)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x11d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strSelection);
		return result;
	}
	BOOL IsDocumentModified()
	{
		BOOL result;
		InvokeHelper(0x127, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL IsCurrentViewModfied()
	{
		BOOL result;
		InvokeHelper(0x126, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL IsCurrentViewModified()
	{
		BOOL result;
		InvokeHelper(0x128, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL UpdateCurrentView()
	{
		BOOL result;
		InvokeHelper(0x125, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long RenameView(LPCTSTR strViewName, LPCTSTR strNewViewName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x12c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, strViewName, strNewViewName);
		return result;
	}
	void SetInformationTemplate(LPCTSTR informationTemplate)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, informationTemplate);
	}
	void SetInformationTemplateContent(LPCTSTR informationTemplateContent)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms, informationTemplateContent);
	}

	// Properties
	//

	CString GetDrawingName()
	{
		CString result;
		GetProperty(0x1, VT_BSTR, (void*)&result);
		return result;
	}
	void SetDrawingName(CString propVal)
	{
		SetProperty(0x1, VT_BSTR, propVal);
	}
	BOOL GetShowRedLining()
	{
		BOOL result;
		GetProperty(0x2, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowRedLining(BOOL propVal)
	{
		SetProperty(0x2, VT_BOOL, propVal);
	}
	short GetRedLineTools()
	{
		short result;
		GetProperty(0x3, VT_I2, (void*)&result);
		return result;
	}
	void SetRedLineTools(short propVal)
	{
		SetProperty(0x3, VT_I2, propVal);
	}
	BOOL GetRenderGroundShadow()
	{
		BOOL result;
		GetProperty(0x68, VT_BOOL, (void*)&result);
		return result;
	}
	void SetRenderGroundShadow(BOOL propVal)
	{
		SetProperty(0x68, VT_BOOL, propVal);
	}
	long GetRenderMode()
	{
		long result;
		GetProperty(0x69, VT_I4, (void*)&result);
		return result;
	}
	void SetRenderMode(long propVal)
	{
		SetProperty(0x69, VT_I4, propVal);
	}
	BOOL GetCameraPlayMode()
	{
		BOOL result;
		GetProperty(0x6b, VT_BOOL, (void*)&result);
		return result;
	}
	void SetCameraPlayMode(BOOL propVal)
	{
		SetProperty(0x6b, VT_BOOL, propVal);
	}
	CString GetFileName()
	{
		CString result;
		GetProperty(0x71, VT_BSTR, (void*)&result);
		return result;
	}
	void SetFileName(CString propVal)
	{
		SetProperty(0x71, VT_BSTR, propVal);
	}
	BOOL GetAntiAliasingOnIdle()
	{
		BOOL result;
		GetProperty(0x72, VT_BOOL, (void*)&result);
		return result;
	}
	void SetAntiAliasingOnIdle(BOOL propVal)
	{
		SetProperty(0x72, VT_BOOL, propVal);
	}
	BOOL GetCameraInertia()
	{
		BOOL result;
		GetProperty(0x73, VT_BOOL, (void*)&result);
		return result;
	}
	void SetCameraInertia(BOOL propVal)
	{
		SetProperty(0x73, VT_BOOL, propVal);
	}
	BOOL GetGroundGrid()
	{
		BOOL result;
		GetProperty(0x74, VT_BOOL, (void*)&result);
		return result;
	}
	void SetGroundGrid(BOOL propVal)
	{
		SetProperty(0x74, VT_BOOL, propVal);
	}
	BOOL GetAutoPlay()
	{
		BOOL result;
		GetProperty(0x75, VT_BOOL, (void*)&result);
		return result;
	}
	void SetAutoPlay(BOOL propVal)
	{
		SetProperty(0x75, VT_BOOL, propVal);
	}
	BOOL GetShowDiapoBar()
	{
		BOOL result;
		GetProperty(0x76, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowDiapoBar(BOOL propVal)
	{
		SetProperty(0x76, VT_BOOL, propVal);
	}
	BOOL GetShowMarkerBar()
	{
		BOOL result;
		GetProperty(0x77, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowMarkerBar(BOOL propVal)
	{
		SetProperty(0x77, VT_BOOL, propVal);
	}
	BOOL GetShowStandardToolBar()
	{
		BOOL result;
		GetProperty(0x78, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowStandardToolBar(BOOL propVal)
	{
		SetProperty(0x78, VT_BOOL, propVal);
	}
	BOOL GetShowRenderToolBar()
	{
		BOOL result;
		GetProperty(0x79, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowRenderToolBar(BOOL propVal)
	{
		SetProperty(0x79, VT_BOOL, propVal);
	}
	BOOL GetShowCameraToolBar()
	{
		BOOL result;
		GetProperty(0x7a, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowCameraToolBar(BOOL propVal)
	{
		SetProperty(0x7a, VT_BOOL, propVal);
	}
	BOOL GetShowTimelineBar()
	{
		BOOL result;
		GetProperty(0x7b, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowTimelineBar(BOOL propVal)
	{
		SetProperty(0x7b, VT_BOOL, propVal);
	}
	BOOL GetShowStatusBar()
	{
		BOOL result;
		GetProperty(0x7c, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowStatusBar(BOOL propVal)
	{
		SetProperty(0x7c, VT_BOOL, propVal);
	}
	BOOL GetShowRedlineToolBar()
	{
		BOOL result;
		GetProperty(0x7d, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowRedlineToolBar(BOOL propVal)
	{
		SetProperty(0x7d, VT_BOOL, propVal);
	}
	BOOL GetShowAnnotationToolBar()
	{
		BOOL result;
		GetProperty(0x7e, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowAnnotationToolBar(BOOL propVal)
	{
		SetProperty(0x7e, VT_BOOL, propVal);
	}
	BOOL GetShowCuttingPlaneToolBar()
	{
		BOOL result;
		GetProperty(0x7f, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowCuttingPlaneToolBar(BOOL propVal)
	{
		SetProperty(0x7f, VT_BOOL, propVal);
	}
	BOOL GetShowCollabToolBar()
	{
		BOOL result;
		GetProperty(0x80, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowCollabToolBar(BOOL propVal)
	{
		SetProperty(0x80, VT_BOOL, propVal);
	}
	CString GetSelection()
	{
		CString result;
		GetProperty(0x85, VT_BSTR, (void*)&result);
		return result;
	}
	void SetSelection(CString propVal)
	{
		SetProperty(0x85, VT_BSTR, propVal);
	}
	CString GetHighlightedObject()
	{
		CString result;
		GetProperty(0x8a, VT_BSTR, (void*)&result);
		return result;
	}
	void SetHighlightedObject(CString propVal)
	{
		SetProperty(0x8a, VT_BSTR, propVal);
	}
	BOOL GetShowGeometryToolBar()
	{
		BOOL result;
		GetProperty(0x90, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowGeometryToolBar(BOOL propVal)
	{
		SetProperty(0x90, VT_BOOL, propVal);
	}
	BOOL GetShowMain3DToolBar()
	{
		BOOL result;
		GetProperty(0x91, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowMain3DToolBar(BOOL propVal)
	{
		SetProperty(0x91, VT_BOOL, propVal);
	}
	BOOL GetShowCameraViewToolBar()
	{
		BOOL result;
		GetProperty(0x92, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowCameraViewToolBar(BOOL propVal)
	{
		SetProperty(0x92, VT_BOOL, propVal);
	}
	BOOL GetShowVisibilityToolBar()
	{
		BOOL result;
		GetProperty(0x93, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowVisibilityToolBar(BOOL propVal)
	{
		SetProperty(0x93, VT_BOOL, propVal);
	}
	CString GetPassword()
	{
		CString result;
		GetProperty(0x95, VT_BSTR, (void*)&result);
		return result;
	}
	void SetPassword(CString propVal)
	{
		SetProperty(0x95, VT_BSTR, propVal);
	}
	BOOL GetMemo3DPack()
	{
		BOOL result;
		GetProperty(0x97, VT_BOOL, (void*)&result);
		return result;
	}
	void SetMemo3DPack(BOOL propVal)
	{
		SetProperty(0x97, VT_BOOL, propVal);
	}
	long GetPos()
	{
		long result;
		GetProperty(0x99, VT_I4, (void*)&result);
		return result;
	}
	void SetPos(long propVal)
	{
		SetProperty(0x99, VT_I4, propVal);
	}
	BOOL GetBorderMask()
	{
		BOOL result;
		GetProperty(0x9d, VT_BOOL, (void*)&result);
		return result;
	}
	void SetBorderMask(BOOL propVal)
	{
		SetProperty(0x9d, VT_BOOL, propVal);
	}
	BOOL GetShowPropertyBar()
	{
		BOOL result;
		GetProperty(0xa5, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowPropertyBar(BOOL propVal)
	{
		SetProperty(0xa5, VT_BOOL, propVal);
	}
	short GetCameraSmoothTime()
	{
		short result;
		GetProperty(0xaa, VT_I2, (void*)&result);
		return result;
	}
	void SetCameraSmoothTime(short propVal)
	{
		SetProperty(0xaa, VT_I2, propVal);
	}
	BOOL GetUseGUID()
	{
		BOOL result;
		GetProperty(0xab, VT_BOOL, (void*)&result);
		return result;
	}
	void SetUseGUID(BOOL propVal)
	{
		SetProperty(0xab, VT_BOOL, propVal);
	}
	BOOL GetShowMeasurementToolBar()
	{
		BOOL result;
		GetProperty(0xb2, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowMeasurementToolBar(BOOL propVal)
	{
		SetProperty(0xb2, VT_BOOL, propVal);
	}
	BOOL GetNoHighlight()
	{
		BOOL result;
		GetProperty(0xb5, VT_BOOL, (void*)&result);
		return result;
	}
	void SetNoHighlight(BOOL propVal)
	{
		SetProperty(0xb5, VT_BOOL, propVal);
	}
	BOOL GetAssySelectionMode()
	{
		BOOL result;
		GetProperty(0xb6, VT_BOOL, (void*)&result);
		return result;
	}
	void SetAssySelectionMode(BOOL propVal)
	{
		SetProperty(0xb6, VT_BOOL, propVal);
	}
	BOOL GetShowTreesBar()
	{
		BOOL result;
		GetProperty(0xbc, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowTreesBar(BOOL propVal)
	{
		SetProperty(0xbc, VT_BOOL, propVal);
	}
	BOOL GetKinematicActivated()
	{
		BOOL result;
		GetProperty(0xc1, VT_BOOL, (void*)&result);
		return result;
	}
	void SetKinematicActivated(BOOL propVal)
	{
		SetProperty(0xc1, VT_BOOL, propVal);
	}
	CString GetProgressFrontColor()
	{
		CString result;
		GetProperty(0xc2, VT_BSTR, (void*)&result);
		return result;
	}
	void SetProgressFrontColor(CString propVal)
	{
		SetProperty(0xc2, VT_BSTR, propVal);
	}
	CString GetProgressBackColor()
	{
		CString result;
		GetProperty(0xc3, VT_BSTR, (void*)&result);
		return result;
	}
	void SetProgressBackColor(CString propVal)
	{
		SetProperty(0xc3, VT_BSTR, propVal);
	}
	BOOL GetWarningIfLessThan32Bits()
	{
		BOOL result;
		GetProperty(0xc5, VT_BOOL, (void*)&result);
		return result;
	}
	void SetWarningIfLessThan32Bits(BOOL propVal)
	{
		SetProperty(0xc5, VT_BOOL, propVal);
	}
	BOOL GetStopIfLessThan32Bits()
	{
		BOOL result;
		GetProperty(0xc8, VT_BOOL, (void*)&result);
		return result;
	}
	void SetStopIfLessThan32Bits(BOOL propVal)
	{
		SetProperty(0xc8, VT_BOOL, propVal);
	}
	CString GetStartupView()
	{
		CString result;
		GetProperty(0xcd, VT_BSTR, (void*)&result);
		return result;
	}
	void SetStartupView(CString propVal)
	{
		SetProperty(0xcd, VT_BSTR, propVal);
	}
	BOOL GetShowViewBar()
	{
		BOOL result;
		GetProperty(0xd2, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowViewBar(BOOL propVal)
	{
		SetProperty(0xd2, VT_BOOL, propVal);
	}
	BOOL GetShowBOMTreeBar()
	{
		BOOL result;
		GetProperty(0xd3, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowBOMTreeBar(BOOL propVal)
	{
		SetProperty(0xd3, VT_BOOL, propVal);
	}
	BOOL GetShowAssemblyTreeBar()
	{
		BOOL result;
		GetProperty(0xd4, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowAssemblyTreeBar(BOOL propVal)
	{
		SetProperty(0xd4, VT_BOOL, propVal);
	}
	BOOL GetShowCollabTreeBar()
	{
		BOOL result;
		GetProperty(0xd5, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowCollabTreeBar(BOOL propVal)
	{
		SetProperty(0xd5, VT_BOOL, propVal);
	}
	long GetEventsMask()
	{
		long result;
		GetProperty(0xeb, VT_I4, (void*)&result);
		return result;
	}
	void SetEventsMask(long propVal)
	{
		SetProperty(0xeb, VT_I4, propVal);
	}
	BOOL GetShowPaper()
	{
		BOOL result;
		GetProperty(0x104, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowPaper(BOOL propVal)
	{
		SetProperty(0x104, VT_BOOL, propVal);
	}
	BOOL GetAssySelectionModeViewportIndicator()
	{
		BOOL result;
		GetProperty(0x105, VT_BOOL, (void*)&result);
		return result;
	}
	void SetAssySelectionModeViewportIndicator(BOOL propVal)
	{
		SetProperty(0x105, VT_BOOL, propVal);
	}
	BOOL GetLoopPlay()
	{
		BOOL result;
		GetProperty(0x10e, VT_BOOL, (void*)&result);
		return result;
	}
	void SetLoopPlay(BOOL propVal)
	{
		SetProperty(0x10e, VT_BOOL, propVal);
	}
	BOOL GetRemoveMeasurementCommands()
	{
		BOOL result;
		GetProperty(0x118, VT_BOOL, (void*)&result);
		return result;
	}
	void SetRemoveMeasurementCommands(BOOL propVal)
	{
		SetProperty(0x118, VT_BOOL, propVal);
	}
	BOOL GetShowInformationBar()
	{
		BOOL result;
		GetProperty(0x12e, VT_BOOL, (void*)&result);
		return result;
	}
	void SetShowInformationBar(BOOL propVal)
	{
		SetProperty(0x12e, VT_BOOL, propVal);
	}
	BOOL GetAutoKeyMode()
	{
		BOOL result;
		GetProperty(0xf2, VT_BOOL, (void*)&result);
		return result;
	}
	void SetAutoKeyMode(BOOL propVal)
	{
		SetProperty(0xf2, VT_BOOL, propVal);
	}
	long GetApplicationProfile()
	{
		long result;
		GetProperty(0x114, VT_I4, (void*)&result);
		return result;
	}
	void SetApplicationProfile(long propVal)
	{
		SetProperty(0x114, VT_I4, propVal);
	}
	long GetOverloadedDocProperties()
	{
		long result;
		GetProperty(0x11e, VT_I4, (void*)&result);
		return result;
	}
	void SetOverloadedDocProperties(long propVal)
	{
		SetProperty(0x11e, VT_I4, propVal);
	}
	BOOL GetPromptToUpdateView()
	{
		BOOL result;
		GetProperty(0x124, VT_BOOL, (void*)&result);
		return result;
	}
	void SetPromptToUpdateView(BOOL propVal)
	{
		SetProperty(0x124, VT_BOOL, propVal);
	}
	BOOL GetPMICrossHLStayOnTop()
	{
		BOOL result;
		GetProperty(0x129, VT_BOOL, (void*)&result);
		return result;
	}
	void SetPMICrossHLStayOnTop(BOOL propVal)
	{
		SetProperty(0x129, VT_BOOL, propVal);
	}
	float GetPMICrossHLOpacity()
	{
		float result;
		GetProperty(0x12a, VT_R4, (void*)&result);
		return result;
	}
	void SetPMICrossHLOpacity(float propVal)
	{
		SetProperty(0x12a, VT_R4, propVal);
	}
	BOOL GetTooltipVisibility()
	{
		BOOL result;
		GetProperty(0x131, VT_BOOL, (void*)&result);
		return result;
	}
	void SetTooltipVisibility(BOOL propVal)
	{
		SetProperty(0x131, VT_BOOL, propVal);
	}
	BOOL GetAllNameOccurences()
	{
		BOOL result;
		GetProperty(0x135, VT_BOOL, (void*)&result);
		return result;
	}
	void SetAllNameOccurences(BOOL propVal)
	{
		SetProperty(0x135, VT_BOOL, propVal);
	}


};
