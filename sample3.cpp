#include <iostream>		// 標準入出力用ライブラリを読み込む
using namespace std;		// 名前空間 std をデフォルトで利用する

// メインルーチン
int main ( void ) // 引数無しで整数(int)型の戻り値を返す main 関数を定義
{
  // 標準入力(cin)から緯度と経度を獲得
  double latitude, longitude; // 2つの倍精度実数型の変数 latitude, longitude を定義
  cout << "緯度と経度を入力して下さい" << endl; // 標準出力 cout に緯度・経度の入力を促すメッセージを表示
  cin >> latitude >> longitude;	// 標準入力から latitude と longitude の値を獲得

  // 標準出力(cout)に緯度と経度を表示
  cout.setf(ios::fixed);	// 固定小数表記を指定
  cout.precision(6);		// 小数点以下の桁数を指定
  cout << "緯度:" << latitude << " 経度:" << longitude << endl; // 文字列と組み合わせて表示

  // 宮城県内かどうかを判別
  double lat_min =  37.77333, lat_max =  39.002778; // 南端の緯度(緯度の最小値)および北端の緯度(緯度の最大値)
  double lng_min = 140.27500, lng_max = 141.675278; // 西端の経度(経度の最小値)および東端の経度(経度の最大値)

  if ( latitude < lat_min	// 「緯度 latitude が最小値 lat_min より小さい」
       || latitude > lat_max	// または「緯度 latitude が最小値 lat_max より大きい」
       || longitude < lng_min	// または「経度 longitude が最小値 lng_min より小さい」
       || longitude > lng_max )	// または「経度 longitude が最小値 lng_max より大きい」
				// ならば「この点は宮城県外である」と判定される
    {		       
      cout << "緯度，経度もしくはその両方が範囲外です" << endl;
    }
  else 				// 以上の条件のどれにも該当しないなら「宮城県内である」と判定される
    { 
      cout << "この点は(おそらく)宮城県内です" << endl;
    }
}
