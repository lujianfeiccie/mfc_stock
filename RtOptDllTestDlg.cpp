// RtOptDllTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RtOptDllTest.h"
#include "RtOptDllTestDlg.h"
#include <vector>
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
// CRtOptDllTestDlg dialog

CRtOptDllTestDlg::CRtOptDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRtOptDllTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRtOptDllTestDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRtOptDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRtOptDllTestDlg)
	DDX_Control(pDX, IDC_LIST_BOX, m_ExcelList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRtOptDllTestDlg, CDialog)
	//{{AFX_MSG_MAP(CRtOptDllTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_Excel, OnBTNExcel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRtOptDllTestDlg message handlers

BOOL CRtOptDllTestDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRtOptDllTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRtOptDllTestDlg::OnPaint() 
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
HCURSOR CRtOptDllTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
typedef struct
{
 CString name;
/////////input///////////
 double numOfStock;//�ɱ�
 double priceOfStock; //�ɼ�

 ////////output////////////
 double totalPrice;//����ֵ
 double lowestPrice;//��ͼ۸�
 double rateOfTotal;//����
}Stock;



void CRtOptDllTestDlg::OnBTNExcel() 
{
	std::vector <Stock> vec;
	std::vector <Stock>::iterator vi;
	double totalPrice = 0;

	CDatabase database;
    CString sSql;
    CString sItem1, sItem2,sItem3;
    CString sDriver;
    CString sDsn;
    CString sFile,sPath;
	
	//��ȡ����������·��,����sPath��
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer ();
    int nPos;
	nPos=sPath.ReverseFind ('\\');
	sPath=sPath.Left (nPos);
	sFile = sPath + "\\stock.xls";     // ������ȡ��Excel�ļ���
    // �����Ƿ�װ��Excel���� "Microsoft Excel Driver (*.xls)" 
    sDriver = GetExcelDriver();
    if (sDriver.IsEmpty())
    {
        // û�з���Excel����
        AfxMessageBox("û�а�װExcel����!");
        return;
    }
    
    // �������д�ȡ���ַ���
    sDsn.Format("ODBC;DRIVER={%s};DSN=' ';DBQ=%s", sDriver, sFile);
    TRY
    {
        // �����ݿ�(��Excel�ļ�)
        database.Open(NULL, false, false, sDsn);
        
        CRecordset recset(&database);
        // ���ö�ȡ�Ĳ�ѯ���.
        sSql =  "SELECT ��˾,�ɱ���,�ɼ�Ԫ" //��������˳��     
				" FROM [sheet1$]" ;                
				" ORDER BY ��˾ ";
		
        // ִ�в�ѯ���
        recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);
		CString tmp = "��˾-->�ɱ�(��)-->�ɼ�(Ԫ)";
		m_ExcelList.AddString( tmp);
		int count = 0;
        // ��ȡ��ѯ���
        while (!recset.IsEOF())
        {
            //��ȡExcel�ڲ���ֵ
			recset.GetFieldValue("��˾", sItem1);       
			recset.GetFieldValue("�ɱ���", sItem2);
			recset.GetFieldValue("�ɼ�Ԫ", sItem3);

			if(sItem1 == ""){
				break;
			}
			Stock stock;
			stock.name = sItem1;
			stock.numOfStock = atof(sItem2);
			stock.priceOfStock = atof(sItem3);			
			stock.totalPrice = stock.numOfStock * stock.priceOfStock;
			stock.lowestPrice = stock.priceOfStock * 100.0f;
			stock.rateOfTotal = 0;
			totalPrice +=stock.totalPrice;
			vec.push_back(stock);//���
            //recset.GetFieldValue("company3", sItem3);
			//��ʾ��ȡ������
			
			tmp.Format("%s-->%s-->%s",sItem1,sItem2,sItem3);
			m_ExcelList.AddString(tmp);
            // �Ƶ���һ��
            recset.MoveNext();
			++count;
        }
        // �ر����ݿ�
        database.Close();
		
		//tmp.Format("count=%d",count);
		tmp = "==================�������======================";
		m_ExcelList.AddString(tmp);
		//MessageBox(tmp);
		double ratio = 0;		
		 for (vi=vec.begin(); vi!=vec.end(); vi++)   
		 {			//cout << *vi; 
			 Stock *s = &*vi;
			 s->rateOfTotal =  s->totalPrice / totalPrice;				 
			 
			 if(s->rateOfTotal < s->lowestPrice) //���� С�� ��ͼ�
			 {	
				 Util::LOG("%.2lf",s->rateOfTotal);

				 double a = s->lowestPrice;
				 double b = s->rateOfTotal;
				 double tmp_ratio =a / b;//�õ��������				
				 if(tmp_ratio>ratio)
				 { 
					ratio = tmp_ratio;//ȡ�����ı������
				 }
			 }			
		 }  // ʹ������� ��*�� �����ݴ��α�ָ������ȡ������
		 
        for (vi=vec.begin(); vi!=vec.end(); vi++)   
		 {		
			 Stock s = *vi;
			 double total = s.rateOfTotal * ratio;//ÿ֧��Ʊ�������Ǯ
			 double numOfStocks = total/s.lowestPrice; //��Ҫ�����֧��Ʊ
			 //Util::LOG("%s %.2lf stocks %.2lf yuan",s.name,numOfStocks,total);		 
			 tmp.Format("%s ����%.2lf�� %.2lfԪ",s.name,numOfStocks,total);
			 m_ExcelList.AddString(tmp);
		 }  // ʹ������� ��*�� �����ݴ��α�ָ������ȡ������
 		 
		 //Util::LOG("%d stocks in total, Lowest cost=%.2lf",count,ratio);
		  tmp.Format("�� %d ֧��Ʊ, ָ���������=%.2lfԪ",count,ratio);
		 m_ExcelList.AddString(tmp);
    }
    CATCH(CDBException, e)
    {
        // ���ݿ���������쳣ʱ...
        AfxMessageBox("���ݿ����: " + e->m_strError);
    }
    END_CATCH	
}

CString CRtOptDllTestDlg::GetExcelDriver()
{
    char szBuf[2001];
    WORD cbBufMax = 2000;
    WORD cbBufOut;
    char *pszBuf = szBuf;
    CString sDriver;
    // ��ȡ�Ѱ�װ����������(������odbcinst.h��)
    if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
        return "";
    
    // �����Ѱ�װ�������Ƿ���Excel...
    do
    {
        if (strstr(pszBuf, "Excel") != 0)
        {
            //���� !
            sDriver = CString(pszBuf);
            break;
        }
        pszBuf = strchr(pszBuf, '\0') + 1;
    }
    while (pszBuf[1] != '\0');
    return sDriver;
}
