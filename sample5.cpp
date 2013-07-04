#include <iostream>		// �W�����o�͗p���C�u������ǂݍ���
#include <iomanip> 		// ���o�͕\�����x���w�肷�邽�߂̃��C�u������ǂݍ���
#include <fstream>	       	// �t�@�C�����o�͗p���C�u������ǂݍ���
#include <string>		// ������p���C�u������ǂݍ���

using namespace std;		// ���O��� std ���f�t�H���g�ŗ��p����

// ���C�����[�`��
int main ( void ) { // ���������Ő���(int)�^�̖߂�l��Ԃ� main �֐����`
  cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
  cout << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
  cout << "  <Folder>" << endl;
  
  ifstream fin("bus-short.csv"); // �t�@�C�����̓X�g���[��
  while ( !fin.eof() ) {	 // fin ���t�@�C���̏I���܂ł��Ă��Ȃ��ԌJ��Ԃ�
    // �t�@�C������1�s�ǂݍ���ŕ�����Ɉꎞ�ۊ�
    string line;		 // �ǂݍ��ݗp������
    getline(fin, line);	 // 1�s�ǂݍ���

    // �ꎞ�ۊǂ��ꂽ�����񂩂�o�X��f�[�^��ǂݍ���
    int ID;			// �o�X��ID�p�̐����^�̕ϐ����`
    char name[100];		// �o�X�▼�p�̕�����^�̕ϐ����`
    double latitude, longitude; // �ܓx�E�o�x�p��2�̔{���x�����^�̕ϐ����`
    sscanf(line.c_str(),
	   "%d,%lf,%lf,%[^\n]",
	   &ID, &latitude, &longitude, name
	   );
    cout << "<Placemark>" 
	 << "<Point><coordinates>"
	 << latitude << "," << longitude << ",0"
	 << "</coordinates></Point>"
	 << "<name>" << name << "</name>"
	 << "<description>[" << ID << "]" << name << "</description>"
	 << "</Placemark>" << endl;
  }

  cout << "</Folder></kml>" << endl;
}
