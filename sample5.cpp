#include <iostream>		// 標準入出力用ライブラリを読み込む
#include <iomanip> 		// 入出力表示精度を指定するためのライブラリを読み込む
#include <fstream>	       	// ファイル入出力ストリーム用ライブラリを読み込む

using namespace std;		// 名前空間 std をデフォルトで利用する

// メインルーチン
int main ( void ) { // 引数無しで整数(int)型の戻り値を返す main 関数を定義
  ifstream fin("bus-short.csv"); // ファイル入力ストリーム

  // KMLを使うためのヘッダを出力
  cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
  cout << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
  cout << "  <Folder>" << endl;

  // ファイルからデータを読み込んで表示させる
  while ( !fin.eof() ) {	 // fos がファイルの最後を指さない限り，処理を繰り返す
    // ファイル入力ストリームからデータを読み込む
    int ID;			// バス停ID用の整数型の変数を定義
    double latitude, longitude; // 緯度・経度用の2つの倍精度実数型の変数を定義
    string name;		// バス停の名前
    fin >> ID >> latitude >> longitude; // ID, 緯度，経度の順に空白で区切られたデータを読み込む
    // バス停の名前は getline 関数を使って取得する．
    // >> 演算子を使うと，バス停名に空白が入っているとき，そこでデータが終わりだと思ってしまう．
    // geline 関数を使うことで，その行の最後までをひとまとまり文字列として name に読み込める
    getline( fin, name );
    // ただし，getline 関数を使うと，経度とバス停名を区切っていた空白もデータとして読み込んでしまうので，
    // 最初の1文字を無視する
    name = name.substr(1);
    
    // 標準出力(cout)に読み込んだデータを加工して表示する
    cout.setf(ios::fixed);	// 固定小数表記を指定
    cout.precision(8);		// 小数点以下の桁数を指定
    // Placemark タグを出力
    cout << "<Placemark>"
	 << "<Point><coordinates>" // 座標を出力
	 << latitude << "," << longitude << ",0"
	 << "</coordinates></Point>"
	 << "<name>" << name << "</name>" // バス停の名前を出力
	 << "<description>[" << ID << "]" << name << "</description>" // 説明にはバス停IDも記述
	 << "</Placemark>" << endl;
  }

  // KMLを使うためのフッタを出力
  cout << "</Folder></kml>" << endl;
}
