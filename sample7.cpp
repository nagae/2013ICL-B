#include <iostream>		// 標準入出力用ライブラリを読み込む
#include <iomanip> 		// 入出力表示精度を指定するためのライブラリを読み込む
#include <fstream>	       	// ファイル入出力ストリーム用ライブラリを読み込む

using namespace std;		// 名前空間 std をデフォルトで利用する

// メインルーチン
int main ( void ) { // 引数無しで整数(int)型の戻り値を返す main 関数を定義
  ifstream fin("bus-short.csv"); // ファイル入力ストリーム

  double target_lat = 38.260297, target_lng =140.88204; // 目標(仙台駅)の緯度・経度
  double range = .05;					// 表示する緯度・経度の範囲
  double lat_min = target_lat - range;			// 表示範囲の西端(経度の最小値)
  double lat_max = target_lat + range;			// 表示範囲の東端(経度の最大値)
  double lng_min = target_lng - range;			// 表示範囲の南端(緯度の最小値)
  double lng_max = target_lng + range;			// 表示範囲の北端(緯度の最大値)

  // KMLを使うためのヘッダを出力
  cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
  cout << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
  cout << "  <Folder>" << endl;

  // 領域を四角で囲む<Placemark>タグを出力
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

  // ファイルからデータを読み込んで表示させる
  while ( !fin.eof() ) {        // fin がファイルの最後を指さない限り，処理を繰り返す
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

    if ( latitude < lat_min	// 「緯度 latitude が最小値 lat_min より小さい」
	 || latitude > lat_max	// または「緯度 latitude が最小値 lat_max より大きい」
	 || longitude < lng_min	// または「経度 longitude が最小値 lng_min より小さい」
	 || longitude > lng_max ) // または「経度 longitude が最小値 lng_max より大きい」
				// ならば何もしない．
      {
	// 何もしない
      }
    else			// 以上の条件のどれにも該当しないなら KML を出力する
      {
	// 標準出力(cout)に読み込んだデータを加工して表示する
	cout.setf(ios::fixed);	// 固定小数表記を指定
	cout.precision(8);	// 小数点以下の桁数を指定
	// Placemark タグを出力
	cout << "<Placemark>"
	     << "<Point><coordinates>" // 座標を出力
	     << longitude << "," << latitude << ",0"
	     << "</coordinates></Point>"
	     << "<name>" << name << "</name>" // バス停の名前を出力
	     << "<description>[" << ID << "]" << name << "</description>" // 説明にはバス停IDも記述
	     << "</Placemark>" << endl;
      }
  }

  // KMLを使うためのフッタを出力
  cout << "</Folder></kml>" << endl;
}
