#include <iostream>		// 標準入出力用ライブラリを読み込む
#include <iomanip> 		// 入出力表示精度を指定するためのライブラリを読み込む
#include <fstream>	       	// ファイル入出力用ライブラリを読み込む
#include <string>		// 文字列用ライブラリを読み込む

using namespace std;		// 名前空間 std をデフォルトで利用する

// メインルーチン
int main ( void ) { // 引数無しで整数(int)型の戻り値を返す main 関数を定義
  cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
  cout << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
  cout << "  <Folder>" << endl;
  
  ifstream fin("bus-short.csv"); // ファイル入力ストリーム
  while ( !fin.eof() ) {	 // fin がファイルの終わりまできていない間繰り返す
    // ファイルから1行読み込んで文字列に一時保管
    string line;		 // 読み込み用文字列
    getline(fin, line);		 // 1行読み込む

    // 一時保管された文字列からバス停データを読み込む
    int ID;			// バス停ID用の整数型の変数を定義
    char name[100];		// バス停名用の文字列型の変数を定義
    double latitude, longitude; // 緯度・経度用の2つの倍精度実数型の変数を定義
    sscanf(line.c_str(),	// 書式つきで読み込む
	   "%d,%lf,%lf,%[^\n]",
	   &ID, &latitude, &longitude, name
	   );
    // Placemark タグを出力
    cout << "<Placemark>"
	 << "<Point><coordinates>" // 座標を出力
	 << latitude << "," << longitude << ",0"
	 << "</coordinates></Point>"
	 << "<name>" << name << "</name>" // バス停の名前を出力
	 << "<description>[" << ID << "]" << name << "</description>" // 説明にはバス停IDも記述
	 << "</Placemark>" << endl;
  }

  cout << "</Folder></kml>" << endl;
}
