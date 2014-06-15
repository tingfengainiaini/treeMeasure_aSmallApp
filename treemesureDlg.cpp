// treemesureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "treemesure.h"
#include "treemesureDlg.h"
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
#include "SkinH.h"
//#include "SkinH_Attach_Ex.h"
#pragma comment(lib, "SkinH.lib")



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreemesureDlg dialog

CTreemesureDlg::CTreemesureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreemesureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreemesureDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_length = _T("");
	//  m_curve = _T("");
	m_crossgrain = _T("");
	m_wide = _T("");
	m_area = _T("");
	m_wormhle = _T("");
	m_deadknot = _T("");
	m_sound = _T("");
	m_decay = _T("");
	//  m_wane = _T("");
	//  m_check = _T("");
	m_check = _T("");
	m_wane = _T("");
	m_sagitta1 = _T("");
	m_sagitta2 = _T("");
	m_thickness = _T("");
}

void CTreemesureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreemesureDlg)
	DDX_Control(pDX, IDC_LIST3, m_list2);
	//}}AFX_DATA_MAP
	//  DDX_Control(pDX, IDC_EDIT1, m_length);
	//  DDX_Control(pDX, IDC_EDIT10, m_curve);
	DDX_Text(pDX, IDC_EDIT1, m_length);
	//  DDX_Text(pDX, IDC_EDIT10, m_curve);
	DDX_Text(pDX, IDC_EDIT11, m_crossgrain);
	//  DDX_Control(pDX, IDC_COMBO1, m_class);
	DDX_Control(pDX, IDC_COMBO1, m_treeclass);
	DDX_Text(pDX, IDC_EDIT2, m_wide);
	DDX_Text(pDX, IDC_EDIT3, m_area);
	DDX_Text(pDX, IDC_EDIT4, m_wormhle);
	DDX_Text(pDX, IDC_EDIT5, m_deadknot);
	DDX_Text(pDX, IDC_EDIT6, m_sound);
	DDX_Text(pDX, IDC_EDIT7, m_decay);
	//  DDX_Text(pDX, IDC_EDIT8, m_wane);
	//  DDX_Control(pDX, IDC_EDIT9, m_check);
	//  DDX_Text(pDX, IDC_EDIT9, m_check);
	DDX_Text(pDX, IDC_EDIT8, m_check);
	DDX_Text(pDX, IDC_EDIT9, m_wane);
	DDX_Text(pDX, IDC_EDIT10, m_sagitta1);
	DDX_Text(pDX, IDC_EDIT12, m_sagitta2);
	DDX_Text(pDX, IDC_EDIT13, m_thickness);
}

BEGIN_MESSAGE_MAP(CTreemesureDlg, CDialog)
	//{{AFX_MSG_MAP(CTreemesureDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CTreemesureDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CTreemesureDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTreemesureDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CTreemesureDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CTreemesureDlg::OnBnClickedButton5)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreemesureDlg message handlers

BOOL CTreemesureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	DWORD dwStyle = m_list2.GetExtendedStyle(); 
    dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl�� 
	dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl�� 
	m_list2.SetExtendedStyle(dwStyle); //������չ��� 
	CImageList   m_l;   
	 m_l.Create(1,18,TRUE|ILC_COLOR32,1,0);   
	m_list2.SetImageList(&m_l,LVSIL_SMALL); 

	m_list2.InsertColumn( 0, "type", LVCFMT_LEFT, 40 );//������
	m_list2.InsertColumn( 1, "length", LVCFMT_LEFT, 50 );//������
    m_list2.InsertColumn( 2, "wide", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 3, "area", LVCFMT_LEFT, 70 );//������
    m_list2.InsertColumn( 4, "wormh", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 5, "deadk", LVCFMT_LEFT, 50 );//������
    m_list2.InsertColumn( 6, "sound", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 7, "decay", LVCFMT_LEFT, 50 );//������
    m_list2.InsertColumn( 8, "check", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 9, "wane", LVCFMT_LEFT, 50 );//������
    m_list2.InsertColumn( 10, "sigat1", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 11, "sigat2", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 12, "crossg", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 13, "thick", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 14, "result", LVCFMT_CENTER, 96 );

	m_treeclass.AddString("��Ҷ");
	m_treeclass.AddString("��Ҷ");
	m_treeclass.SelectString( 0, "��Ҷ");
	SkinH_Attach();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTreemesureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTreemesureDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTreemesureDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CTreemesureDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_length = "12";//�������д��
	MessageBox("����ûд��");
	UpdateData(FALSE);
}
//�����CStringת��Ϊfloat
float cs2f(CString a){
	float b=0.0;
	sscanf(a, "%f", &b );
	return b;
}
//�ж�ľ�ĵȼ��ĺ���
int tree_grade(int nIndex, float length,float wide, float deadknot, float decay, float area,\
	float wormhle, float sound,float wane,float sagitta1,float sagitta2,float check,float crossgrain,float thickness){
	if(nIndex == 1){//��
		//MessageBox("��Ҷ");
		if(sound <=15  ){//&& deadknot<=4 && decay<=0 && check<=5 && wormhle<=1 && wane<=5 && sagitta2<=0.3 && sagitta1<=1 && crossgrain<=5){
			return 1;
		}else if(sound <=25  ){//&& deadknot<=6 && decay<=2 && check<=10 && wormhle<=4 && wane<=20 && sagitta2<=0.5 && sagitta1<=2 && crossgrain<=10){
			return 2;
		}else if(sound <=40  ){//&& deadknot<=10 && decay<=30 && check<=30 && wormhle<=15 && wane<=40 && sagitta2<=2 && sagitta1<=3 && crossgrain<=20){
			return 3;
		}else if(decay<=30 && wane<=60 && sagitta2<=3){//&& deadknot<=10 &&  check<=30 && wormhle<=15 &&  sagitta1<=3 && crossgrain<=20){
			return 4;
		}else{
			return 5;
		}
	}else{//��Ҷ
		//MessageBox("��Ҷ");
		if(sound <=15  ){//&& deadknot<=3 && decay<=0 && check<=10 && wormhle<=1 && wane<=10 && sagitta2<=0.5 && sagitta1<=1 && crossgrain<=5){
			return 1;
		}else if(sound <=25  ){//&& deadknot<=5 && decay<=5 && check<=15 && wormhle<=2 && wane<=20 && sagitta2<=1 && sagitta1<=2 && crossgrain<=10){
			return 2;
		}else if(sound <=40  ){//&& deadknot<=6 && decay<=10 && check<=40 && wormhle<=8 && wane<=40 && sagitta2<=2 && sagitta1<=3 && crossgrain<=20){
			return 3;
		}else if(decay<=30 && wane<=60 && sagitta2<=4){//&& deadknot<=10 &&  check<=30 && wormhle<=15 &&  sagitta1<=3 && crossgrain<=20){
			return 4;
		}else{
			return 5;
		}
	}
	return 0;
}
void CTreemesureDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_length == "" || m_wide=="" ){// || m_deadknot == "" || m_decay=="" \
		|| m_area=="" || m_wormhle == "" ||m_sound=="" || m_wane=="" || m_sagitta1=="" || m_sagitta2=="" || m_check==""){
		MessageBox("���벻��Ϊ�գ�");
		return;
	}
	//��ø�������ı���
	float length,wide, deadknot, decay, area,wormhle, sound,wane,sagitta1,sagitta2,check,crossgrain,thickness;

	length = cs2f(m_length);//��
	wide = cs2f(m_wide);//��
	area = cs2f(m_area);//���
	thickness=cs2f(m_thickness);//���

	deadknot = cs2f(m_deadknot)/length;//����ĳ�1m��Χ�ڵ����������6��
	decay = cs2f(m_decay)/area*100;//���������2%���������
	
	wormhle = cs2f(m_wormhle)/length;//����ĳ�1m�ڵĳ��۸���
	sound= cs2f(m_sound)/wide*100;//������ߴ��15%�ĲĿ�
	wane=cs2f(m_wane)/wide*100;//����������ȱ�ǳߴ��20%�Ŀ�
	sagitta1 = cs2f(m_sagitta1)/length*100;//˳�������ȡ�2%��
	sagitta2 = cs2f(m_sagitta2)/wide*100;//���������ȡ�0.5%��
	check=cs2f(m_check)/length*100;//���ơ���Ƥ���ȡ�10%�Ĳĳ���
	crossgrain = cs2f(m_crossgrain)/thickness;//б����б�߶ȡ�10%��
	//��ʼ�ж�
	if(length < 2){
		MessageBox("���Ȳ��㣡");
		return;
	}
	//char   buf[32]; 
	//_gcvt(length,   16,   buf);
	
	//CString str;
	//str.Format("%d", area);
	//MessageBox(str);

	int nIndex = m_treeclass.GetCurSel();
	int treeGrade = tree_grade(nIndex,length,wide, deadknot, decay, \
		area,wormhle, sound,wane,sagitta1,sagitta2,check,crossgrain,thickness);
	if(nIndex == 1){//��
		//MessageBox("��Ҷ");
		if(treeGrade ==1  ){
			MessageBox("��Ҷ �صȾ��");
		}else if(treeGrade ==2   ){
			MessageBox("��Ҷ һ�Ⱦ��");
		}else if(treeGrade ==3  ){
			MessageBox("��Ҷ ���Ⱦ��");
		}else if(treeGrade ==4  ){
			MessageBox("��Ҷ ���Ⱦ��");
		}else{
			MessageBox("��Ҷ ���ʾ��");
		}
	}else{//��Ҷ
		//MessageBox("��Ҷ");
		if(treeGrade ==1  ){
			MessageBox("��Ҷ �صȾ��");
		}else if(treeGrade ==2   ){
			MessageBox("��Ҷ һ�Ⱦ��");
		}else if(treeGrade ==3 ){
			MessageBox("��Ҷ ���Ⱦ��");
		}else if(treeGrade ==4  ){
			MessageBox("��Ҷ ���Ⱦ��");
		}else{
			MessageBox("��Ҷ ���ʾ��");
		}
	}
	
}



void CTreemesureDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_length = "";
	m_wide = "";
	m_area = "";
	m_sagitta1="";
	m_sagitta2="";
	m_crossgrain="";
	m_wide="";
	 m_area="";
	m_wormhle="";
	m_deadknot="";
	m_sound="";
	m_decay="";
    m_check="";
	m_wane="";
	UpdateData(FALSE);
}


void CTreemesureDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = "�����ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||";
	CFileDialog fileDlg(true, "txt","*.txt", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY,szFilter, NULL);
	CString	FilePathName="";
	if(fileDlg.DoModal()==IDOK){
		FilePathName = fileDlg.GetPathName();
	}else{
		return;
	}
	if(FilePathName == ""){
		return;
	}
	//����б�
	m_list2.DeleteAllItems();
	ifstream myfile (FilePathName);
	char buffer[256];
	string s;
	//��ø�������ı���
	  int treetype;
	  float length,wide, deadknot, decay, area,wormhle, sound,wane,sagitta1,sagitta2,check,crossgrain,thickness;
	  while (!myfile.eof() )
	  {	
		myfile.getline (buffer,50);
		//ÿ�й�13������
        sscanf(buffer,"%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t",\
			&treetype,&length,&wide, &deadknot, &decay, &area,&wormhle,\
			&sound,&wane,&sagitta1,&sagitta2,&check,&crossgrain,&thickness);
		int i = m_list2.GetItemCount();//��ȡlist�����ж�����
		CString ttt;
		ttt.Format("%d",treetype);
		m_list2.InsertItem(i,ttt);//����һ���У����������е�����Ϊi������
		ttt.Format("%6.2f",length);
		m_list2.SetItemText(i,1,ttt);//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		ttt.Format("%6.2f",wide);
		m_list2.SetItemText(i,2,ttt);
		ttt.Format("%6.2f",deadknot);
		m_list2.SetItemText(i,3,ttt);
		ttt.Format("%6.2f",decay);
		m_list2.SetItemText(i,4,ttt);
		ttt.Format("%6.2f",area);
		m_list2.SetItemText(i,5,ttt);
		ttt.Format("%6.2f",wormhle);
		m_list2.SetItemText(i,6,ttt);
		ttt.Format("%6.2f",sound);
		m_list2.SetItemText(i,7,ttt);
		ttt.Format("%6.2f",wane);
		m_list2.SetItemText(i,8,ttt);
		ttt.Format("%6.2f",sagitta1);
		m_list2.SetItemText(i,9,ttt);
		ttt.Format("%6.2f",sagitta2);
		m_list2.SetItemText(i,10,ttt);
		ttt.Format("%6.2f",check);
		m_list2.SetItemText(i,11,ttt);
		ttt.Format("%6.2f",crossgrain);
		m_list2.SetItemText(i,12,ttt);
		ttt.Format("%6.2f",thickness);
		m_list2.SetItemText(i,13,ttt);

		//1����Ҷ��0����Ҷ
		int treeGrade = tree_grade(treetype,length,wide, deadknot, decay, area,wormhle, \
			sound,wane,sagitta1,sagitta2,check,crossgrain,thickness);
		if(treeGrade ==1  ){
			m_list2.SetItemText(i,14,"�ص�");
		}else if(treeGrade ==2   ){
			m_list2.SetItemText(i,14,"һ��");
		}else if(treeGrade ==3 ){
			m_list2.SetItemText(i,14,"����");
		}else if(treeGrade ==4  ){
			m_list2.SetItemText(i,14,"����");
		}else{
			m_list2.SetItemText(i,14,"����");
		}
	  }

}

//������ť
void CTreemesureDlg::OnBnClickedButton5()
{
	TCHAR szFile[MAX_PATH] = {0};
	OPENFILENAME OpenFileName;
	OpenFileName.lStructSize       = sizeof(OPENFILENAME);
	OpenFileName.hwndOwner         = m_hWnd;
	OpenFileName.hInstance         = AfxGetInstanceHandle();
	OpenFileName.lpstrFilter       = _T("SkinSharpƤ���ļ�(*.she)\0*.she\0\0");
	OpenFileName.lpstrCustomFilter = NULL;
	OpenFileName.nMaxCustFilter    = 0;
	OpenFileName.nFilterIndex      = 0;
	OpenFileName.lpstrFile         = szFile;
	OpenFileName.nMaxFile          = sizeof(szFile);
	OpenFileName.lpstrFileTitle    = NULL;
	OpenFileName.nMaxFileTitle     = 0;
	OpenFileName.lpstrInitialDir   = _T(".\\");
	OpenFileName.lpstrTitle        = _T("��ѡ��SkinSharpƤ���ļ�");
	OpenFileName.nFileOffset       = 0;
	OpenFileName.nFileExtension    = 0; 
	OpenFileName.lpstrDefExt       = _T("she");
	OpenFileName.Flags             = OFN_SHOWHELP | OFN_EXPLORER;
	
	if(!GetOpenFileName(&OpenFileName))
		return;

	SkinH_AttachEx(szFile,NULL);
}
