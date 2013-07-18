#include <iostream>		// ɸ���������ѥ饤�֥����ɤ߹���
#include <iomanip> 		// ������ɽ�����٤���ꤹ�뤿��Υ饤�֥����ɤ߹���
#include <fstream>	       	// �ե����������ϥ��ȥ꡼���ѥ饤�֥����ɤ߹���

using namespace std;		// ̾������ std ��ǥե���Ȥ����Ѥ���

// �ᥤ��롼����
int main ( void ) { // ����̵��������(int)��������ͤ��֤� main �ؿ������
  ifstream fin("bus-short.csv"); // �ե��������ϥ��ȥ꡼��

  double target_lat = 38.260297, target_lng =140.88204; // ��ɸ(�����)�ΰ��١�����
  double range = .05;					// ɽ��������١����٤��ϰ�
  double lat_min = target_lat - range;			// ɽ���ϰϤ���ü(���٤κǾ���)
  double lat_max = target_lat + range;			// ɽ���ϰϤ���ü(���٤κ�����)
  double lng_min = target_lng - range;			// ɽ���ϰϤ���ü(���٤κǾ���)
  double lng_max = target_lng + range;			// ɽ���ϰϤ���ü(���٤κ�����)

  // KML��Ȥ�����Υإå������
  cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
  cout << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
  cout << "  <Folder>" << endl;

  // �ΰ��ͳѤǰϤ�<Placemark>���������
  cout << "    <Placemark>" << endl;
  cout << "      <Style><LineStyle><color>7f0000ff</color><width>4</width></LineStyle></Style>" << endl;
  cout << "      <LineString><coordinates>" << endl;
  cout << "      " << lng_min << "," << lat_min << ",0" << endl;
  cout << "      " << lng_min << "," << lat_max << ",0" << endl;
  cout << "      " << lng_max << "," << lat_max << ",0" << endl;
  cout << "      " << lng_max << "," << lat_min << ",0" << endl;
  cout << "      " << lng_min << "," << lat_min << ",0" << endl;
  cout << "      </coordinates></LineString>" << endl;
  cout << "    </Placemark>" << endl;

  // �ե����뤫��ǡ������ɤ߹����ɽ��������
  while ( !fin.eof() ) {        // fin ���ե�����κǸ��ؤ��ʤ��¤ꡤ�����򷫤��֤�
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

    if ( latitude < lat_min	// �ְ��� latitude ���Ǿ��� lat_min ��꾮������
	 || latitude > lat_max	// �ޤ��ϡְ��� latitude ���Ǿ��� lat_max ����礭����
	 || longitude < lng_min	// �ޤ��ϡַ��� longitude ���Ǿ��� lng_min ��꾮������
	 || longitude > lng_max ) // �ޤ��ϡַ��� longitude ���Ǿ��� lng_max ����礭����
				// �ʤ�в��⤷�ʤ���
      {
	// ���⤷�ʤ�
      }
    else			// �ʾ�ξ��Τɤ�ˤ⳺�����ʤ��ʤ� KML ����Ϥ���
      {
	// ɸ�����(cout)���ɤ߹�����ǡ�����ù�����ɽ������
	cout.setf(ios::fixed);	// ���꾮��ɽ�������
	cout.precision(8);	// �������ʲ��η�������
	// Placemark ���������
	cout << "<Placemark>"
	     << "<Point><coordinates>" // ��ɸ�����
	     << longitude << "," << latitude << ",0"
	     << "</coordinates></Point>"
	     << "<name>" << name << "</name>" // �Х����̾�������
	     << "<description>[" << ID << "]" << name << "</description>" // �����ˤϥХ���ID�⵭��
	     << "</Placemark>" << endl;
      }
  }

  // KML��Ȥ�����Υեå������
  cout << "</Folder></kml>" << endl;
}
