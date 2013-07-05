#include <iostream>             // 標準入出力用ライブラリを読み込む
using namespace std;            // 名前空間 std をデフォルトで利用する

// メインルーチン
int main ( void ) 		// 引数無しで整数(int)型の戻り値を返す main 関数を定義
{
  // 緯度・経度を格納するための倍精度実数(double)型の変数を定義
  double latitude = 38.2523;	// 緯度
  double longitude = 140.856;	// 経度

  // 標準出力(cout)に KML を表示
  // KMLを使うためのヘッダを出力
  cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
       << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;

  // 地図上の目印を<Placemark>〜</Placemark>の間に定義
  cout << "  <Placemark>\n"
    // 目印の名前を<name>〜</name>の間に記述
       << "    <name>仙台城址</name>\n"
    // 目印の説明として緯度と経度を<description>〜</description>の間に記述
       << "    <description>\n"
       << "    緯度:" << latitude << " 経度:" << longitude << "\n"
       << "    </description>" << endl
    // 目印の構成要素として1つの点(マーク)を<Point>〜</Point>の間に定義
    // この点の座標を<coordinates>〜</coordinates>の間に経度,緯度,標高の順に記述
       << "    <Point><coordinates>\n"
       << "      " << longitude << "," << latitude << ",0\n"
       << "    </coordinates></Point>\n"
       << "  </Placemark>" << endl;

  // KMLを使うためのフッタを出力
  cout << "</kml>" << endl;
}
