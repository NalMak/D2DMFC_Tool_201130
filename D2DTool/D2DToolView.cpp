
// D2DToolView.cpp: CD2DToolView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "D2DTool.h"
#endif

#include "D2DToolDoc.h"
#include "D2DToolView.h"
#include "DeviceManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND g_hWnd;
// CD2DToolView

IMPLEMENT_DYNCREATE(CD2DToolView, CView)

BEGIN_MESSAGE_MAP(CD2DToolView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CD2DToolView 생성/소멸

CD2DToolView::CD2DToolView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CD2DToolView::~CD2DToolView()
{
}

BOOL CD2DToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CD2DToolView 그리기

void CD2DToolView::OnDraw(CDC* /*pDC*/)
{
	CD2DToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	DeviceManager::GetInstance()->Begin();

	DeviceManager::GetInstance()->End();
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CD2DToolView 인쇄

BOOL CD2DToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CD2DToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CD2DToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CD2DToolView 진단

#ifdef _DEBUG
void CD2DToolView::AssertValid() const
{
	CView::AssertValid();
}

void CD2DToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CD2DToolDoc* CD2DToolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CD2DToolDoc)));
	return (CD2DToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CD2DToolView 메시지 처리기


void CD2DToolView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	g_hWnd = m_hWnd;

	DeviceManager::GetInstance()->Initialize();


	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}
