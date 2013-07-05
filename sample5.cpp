#include <iostream>		// ɸ���������ѥ饤�֥����ɤ߹���
#include <iomanip> 		// ������ɽ�����٤���ꤹ�뤿��Υ饤�֥����ɤ߹���
#include <fstream>	       	// �ե����������ϥ��ȥ꡼���ѥ饤�֥����ɤ߹���

using namespace std;		// ̾������ std ��ǥե���Ȥ����Ѥ���

// �ᥤ��롼����
int main ( void ) { // ����̵��������(int)��������ͤ��֤� main �ؿ������
  ifstream fin("bus-short.csv"); // �ե��������ϥ��ȥ꡼��

  // KML��Ȥ�����Υإå������
  cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
  cout << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
  cout << "  <Folder>" << endl;

  // �ե����뤫��ǡ������ɤ߹����ɽ��������
  while ( !fin.eof() ) {	 // fos ���ե�����κǸ��ؤ��ʤ��¤ꡤ�����򷫤��֤�
    // �ե��������ϥ��ȥ꡼�फ��ǡ������ɤ߹���
    int ID;			// �Х���ID�Ѥ����������ѿ������
    double latitude, longitude; // ���١������Ѥ�2�Ĥ������ټ¿������ѿ������
    string name;		// �Х����̾��
    fin >> ID >> latitude >> longitude; // ID, ���١����٤ν�˶���Ƕ��ڤ�줿�ǡ������ɤ߹���
    // �Х����̾���� getline �ؿ���ȤäƼ������롥
    // >> �黻�Ҥ�Ȥ��ȡ��Х���̾�˶������äƤ���Ȥ��������ǥǡ������������ȻפäƤ��ޤ���
    // geline �ؿ���Ȥ����Ȥǡ����ιԤκǸ�ޤǤ�ҤȤޤȤޤ�ʸ����Ȥ��� name ���ɤ߹����
    getline( fin, name );
    // ��������getline �ؿ���Ȥ��ȡ����٤ȥХ���̾����ڤäƤ��������ǡ����Ȥ����ɤ߹���Ǥ��ޤ��Τǡ�
    // �ǽ��1ʸ����̵�뤹��
    name = name.substr(1);
    
    // ɸ�����(cout)���ɤ߹�����ǡ�����ù�����ɽ������
    cout.setf(ios::fixed);	// ���꾮��ɽ�������
    cout.precision(8);		// �������ʲ��η�������
    // Placemark ���������
    cout << "<Placemark>"
	 << "<Point><coordinates>" // ��ɸ�����
	 << latitude << "," << longitude << ",0"
	 << "</coordinates></Point>"
	 << "<name>" << name << "</name>" // �Х����̾�������
	 << "<description>[" << ID << "]" << name << "</description>" // �����ˤϥХ���ID�⵭��
	 << "</Placemark>" << endl;
  }

  // KML��Ȥ�����Υեå������
  cout << "</Folder></kml>" << endl;
}
