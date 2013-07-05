#include <iostream>		// �W�����o�͗p���C�u������ǂݍ���
#include <iomanip> 		// ���o�͕\�����x���w�肷�邽�߂̃��C�u������ǂݍ���
#include <fstream>	       	// �t�@�C�����o�̓X�g���[���p���C�u������ǂݍ���

using namespace std;		// ���O��� std ���f�t�H���g�ŗ��p����

// ���C�����[�`��
int main ( void ) { // ���������Ő���(int)�^�̖߂�l��Ԃ� main �֐����`
  ifstream fin("bus-short.csv"); // �t�@�C�����̓X�g���[��
  while ( !fin.eof() ) {
    // �t�@�C�����̓X�g���[������f�[�^��ǂݍ���
    int ID;			// �o�X��ID�p�̐����^�̕ϐ����`
    double latitude, longitude; // �ܓx�E�o�x�p��2�̔{���x�����^�̕ϐ����`
    string name;		// �o�X��̖��O
    fin >> ID >> latitude >> longitude; // ID, �ܓx�C�o�x�̏��ɋ󔒂ŋ�؂�ꂽ�f�[�^��ǂݍ���
    // �o�X��̖��O�� getline �֐����g���Ď擾����D
    // >> ���Z�q���g���ƁC�o�X�▼�ɋ󔒂������Ă���Ƃ��C�����Ńf�[�^���I��肾�Ǝv���Ă��܂��D
    // geline �֐����g�����ƂŁC���̍s�̍Ō�܂ł��ЂƂ܂Ƃ܂蕶����Ƃ��� name �ɓǂݍ��߂�
    getline( fin, name );
    // �������Cgetline �֐����g���ƁC�o�x�ƃo�X�▼����؂��Ă����󔒂��f�[�^�Ƃ��ēǂݍ���ł��܂��̂ŁC
    // �ŏ���1�����𖳎�����
    name = name.substr(1);
    
    // �W���o��(cout)�ɓǂݍ��񂾃f�[�^�����H���ĕ\������
    cout.setf(ios::fixed);	// �Œ菬���\�L���w��
    cout.precision(8);		// �����_�ȉ��̌������w��
    cout << setw(4) << ID << " "
	 << setw(10) << latitude << " "
	 << setw(10) << longitude << " "
	  << name << endl;
  }
}
