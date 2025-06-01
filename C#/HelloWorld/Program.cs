using System;// https://aka.ms/new-console-template for more information
namespace HelloWorld
{
    #region 枚舉
    //枚舉名稱以E_開頭
    enum E_Result
    {
        E_Success = 0,//默認值,.可設定
        E_Fail = 1,//默認值(累加上一個的值)
        E_Error = 2,//默認值(累加上一個的值)
        E_Unknown = 3//默認值(累加上一個的值)
    }
    //在nameSpace,class,program中定義枚舉,這樣可以在其他類別中使用
    //不能在函數裡面定義枚舉,這樣會報錯
    //他的tostring()方法會返回枚舉的名稱,而不是數字

    #endregion
    static class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            #region wtf
            //用來摺疊代碼,像區塊一樣    
            //為預處理指令,只有在編輯時有用
            //編譯時會自動刪除
            #endregion
            #region 變量
            //變量
            //sbyte -128~~127
            //int   +-億
            //short +-五位數
            //long
            //sbyte sb = 127;
            //Console.WriteLine("請輸入你的名字:" + sb);
            #endregion
            #region 無符號

            // uint
            // ulong
            // byte
            #endregion
            #region 浮點
            //double d = 3.14;
            //float f = 3.14f;
            //decimal de = 3.14m;
            //decimal是精度最高的,但是運算速度最慢
            //要加m在後面
            //這裡要加入f在後面是因為C#的小數默認類型是double
            #endregion
            #region 字符串
            //bool b = true;
            //bool b2 = false;
            //bool是布林值,只有true和false兩個值
            //Console.WriteLine(b + "_" + b2);
            //字串是不可變的,所以要用StringBuilder來改變字串
            //StringBuilder是可變的,但是要用using來引用命名空間
            #endregion
            #region 變量命名規則
            //扁兩用
            //nameMy = "123"; //變量命名規則,不能用中文命名
            //類別命名規則,第一個字母要大寫
            //變量命名規則,不能用中文命名   
            //變量命名規則,不能用數字開頭
            //變量命名規則,不能用特殊符號命名
            //變量命名規則,不能用關鍵字命名
            //變量命名規則,不能用保留字命名
            //變量命名規則,不能用空格命名
            //變量命名規則,不能用下劃線開頭
            //變量命名規則,不能用下劃線結尾
            //NameMy = "123"; //類別命名規則,第一個字母要大寫
            #endregion
            #region 數組
            int i = 0;
            Console.WriteLine(i < 0 ? "i小於0" : "i大於0");
            E_Result result = E_Result.E_Success;
            //主要放在if判斷中左使用or switch中
            switch (result)
            {
                case E_Result.E_Success:
                    Console.WriteLine("成功");
                    break;
                case E_Result.E_Fail:
                    Console.WriteLine("失敗");
                    break;
                case E_Result.E_Error:
                case E_Result.E_Unknown:
                    Console.WriteLine("未知");
                    //switch中可以不寫break,這樣會執行到下一個case貫穿功能
                    break;
                default:
                    Console.WriteLine("未知錯誤");
                    break;
            }
            result = (E_Result)Enum.Parse(typeof(E_Result), "E_Success");//將字串轉換成枚舉類型,這裡要用typeof來指定類型,不然會報錯
                                                                         //Enum.Parse(typeof(E_Result), "E_Fail")//將字串轉換成枚舉類型,這裡要用typeof來指定類型,不然會報錯
            Console.WriteLine(result.ToString());//將枚舉轉換成字串,這裡要用ToString()來轉換,不然會報錯
            Console.WriteLine("{0}{1}{2}{3}", result, result, result, result);//將枚舉轉換成整數,這裡要用(int)來轉換,不然會報錯
            int[] arr = new int[5];//定義一個整數陣列,這裡要用new來初始化,不然會報錯
            int[] axr = new int[5] { 1, 2, 3, 4, 5 };//定義一個整數陣列,這裡要用new來初始化,不然會報錯
            int[] adr = { 1, 2, 3, 4, 5 };//定義一個整數陣列,這裡要用new來初始化,不然會報錯
            int[] arr2 = new int[6];//定義一個整數陣列,這裡要用new來初始化,不然會報錯
            for (int j = 0; j < arr.Length; j++)
            {
                arr2[i] = axr[i];//輸出陣列的值,這裡要用arr[j]來輸出,不然會報錯
            }
            axr = arr2;//給陣列賦值,這裡要用arr[i]來賦值,不然會報錯
            int [,] arr3 = new int[2, 3];//定義一個二維陣列,這裡要用new來初始化,不然會報錯
            int[,] arr4 = new int[2, 3] { { 1, 2, 3 }, { 4, 5, 6 } };//定義一個二維陣列,這裡要用new來初始化,不然會報錯
            int[,] arr5 = { { 1, 2, 3 }, { 4, 5, 6 } };//定義一個二維陣列,這裡要用new來初始化,不然會報錯
            int [][] arr6 = new int[2][];//定義一個不規則陣列,這裡要用new來初始化,不然會報錯
            int[][] arr7 = new int[2][] { new int[3] { 1, 2, 3 }, new int[4] { 4, 5, 6, 7 } };//定義一個不規則陣列,這裡要用new來初始化,不然會報錯
            int[][] arr8 = { new int[3] { 1, 2, 3 }, new int[4] { 4, 5, 6, 7 } };//定義一個不規則陣列,這裡要用new來初始化,不然會報錯
        }
    };

}