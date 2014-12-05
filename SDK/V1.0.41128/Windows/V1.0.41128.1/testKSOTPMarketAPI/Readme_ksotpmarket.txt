/**
 *@�ļ�  ��Readme_ksotpmarket.txt  ��������API��Դ����˵���ļ�
 *@����  : xdhu
 *@ϵͳ����API���Գ���
 *@��˾����ʤ�ƽ��˴�
 *@�޸���ʷ��
    20121203  ����
 */
һ���ļ�˵����
testKSOTPMarketAPI�ļ��а��������ļ���
Դ�ļ�   testKSOTPMarketAPI.cpp   event.cpp
ͷ�ļ�   testKSOTPMarketAPI.h     event.h
linux����makefile�ļ�   makefile
windows����vc��Ŀ�ļ�   testKSOTPMarketAPI.sln��testKSOTPMarketAPI.vcproj
�����ļ�		Readme_ksotpmarket.txt, Readme_ksotpmarket_en.txt

�����ļ����ܣ�
testKSOTPMarketAPI.h/testKSOTPMarketAPI.cpp  			��Ҫʵ�ֲ���libksmarketdataapi.so��̬��Ļ�������
event.h/event.cpp                    				��Ҫ��װһ��windows/linux���ݵ��¼�����
makefile 			    				��Ҫʵ����linuxƽ̨�£����Կ�ִ�г���ı��롣
testKSOTPMarketAPI.sln��testKSOTPMarketAPI.vcproj		��Ҫʵ����windowsƽ̨�£����Կ�ִ�г���ı��롣

����linuxƽ̨���롢����˵��

1������˵��
   makefile�ṩ32λ���Գ����64λ���Գ���ı��롣

   1��  ������
	����ȷ����������װ��gcc 4.1.2�������ϰ汾
	��linux��shell�������� ���� gcc -v ���Բ鿴gcc�İ汾��Ϣ
	�Ͱ汾��gcc���ܵ��±������
   
   2��  ��α���
	��linux�� shell������������make���
	make   		����64λ���Գ���Ĭ�ϣ�
	make  vtype=32r ����32λ���Գ���
        make  vtype=64r ����64λ���Գ���

   3��  ����Ŀ��
	make �� make vtype=64r ���� run Ŀ¼�£����� testKSOTPMarketAPI_64 ��ִ���ļ�������32λ���Գ���
        make vtype=32r         ���� run Ŀ¼�£����� testKSOTPMarketAPI_32 ��ִ���ļ�������64λ���Գ���
	
   4��  ע������
	�ڵ�ǰ����������32λ��64λ����ʱ��ִ��һ��make�������Ҫִ�� make clean ,ɾ���ϴα�����м�Ŀ���ļ���
	�Է�ֹ����64λ��������32λ���м�Ŀ���ļ������32λ����������64λ���м�Ŀ���ļ������±������

2������˵��
   
   1�����м��
      ���Դ�������У���Ҫȷ����̬��libksmarketdataapi.so,libkslkc64r.so(32λ����libkslkc32r.so)�ļ��Ĵ��ڡ������������32λ��64λ��libksmarketdataapi.so���ļ�����ͬ���ֱ���KSOTPMarketAPI/linux32/��   KSOTPMarketAPI/linux64Ŀ¼�¡���libkslkc32r.so��KSOTPMarketAPI/linux32/Ŀ¼�£�libkslkc64r.so��KSOTPMarketAPI/linux64/Ŀ¼�£�
      ����Ƿ��Ѿ��ɹ���������Գ���Ŀ�ִ���ļ��� ����׶ν���runĿ¼��������Ӧ�Ŀ�ִ�г��򣩡�

   2) ��̬���ļ���ִ����������
      
      ȷ����̬�� libksmarketdataapi.so���п�ִ�����ԡ�����ͨ��ls -l libksmarketdataapi.so�鿴�ļ������ԡ�
      ȷ����̬�� libkslkc64r.so����libkslc32r.so�����п�ִ�����ԡ�����ͨ��ls -l libkslkc64r.so ��libkslkc32r.so�����鿴�ļ����ԡ�
      ����̬�ⲻ�߱���ִ�����ԣ�������linux shell�������£�ͨ�� chmod +x libksmarketdataapi.so��ʵ�֡� ��������ο� man 1 chmod

   3�����ö�̬�����·��
      ����libksmarketdataapi.so�ľ���·��Ϊ/xxx/yyy/zzz/libksmarketdataapi.so�������·�ʽ���ö�̬�����·�������Բο�man 3 dlopen

      	 ���Խ�libksmarketdataapi.so,libkslkc64r.so(��libkslkc32r.so��������Ŀ¼·������ӵ�LD_LIBRARY_PATH���������С�
	 LD_LIBRARY_PATH=/xxx/yyy/zzz/��${LD_LIBRARY_PATH};  export LD_LIBRARY_PATH

   4) ��黷�����õ���ȷ��
      a)����ִ�г���Զ�̬������ü����Ƿ���ȷ
	ldd  testKSOTPMarketAPI_32   ���32λ���Գ���Զ�̬��ļ���
	ldd  testKSOTPMarketAPI_64   ���64λ���Գ���Զ�̬��ļ���
      b)�鿴��ǰ�Ķ�̬��İ汾��Ϣ
	strings libksmarketdataapi.so|grep KSFT_API_Version
   5��ע������
      �������ȷ���У�����Ҫ��ý��˴����Ȩ�ļ�KSInterB2C.lkc, ȷ���ڿ�ִ���ļ�����Ŀ¼����KSInterB2C.lkc�ļ����������ϵ���߻�ȡ��Ȩ�ļ���


����Windowsƽ̨���롢����˵��

1������˵��
   ��Ҫͨ��Visual Studio 2005 IDE���������ñ��롣

   1) ������
   ����ȷ����������װ��Visual Studio 2005�����ϰ汾��
   
   2����α���
   ͨ��vs��testKSOTPMarketAPI.sln�ļ������뼴�ɡ�
   
   3������Ŀ��
   ��runĿ¼������testKSOTPMarketAPI.exe��ִ���ļ���

2������˵��
   ȷ��runĿ¼����KSMarketDataAPI.dll,cpack.dll,lkcdll.dll
   ��runĿ¼��ִ��testKSOTPMarketAPI.exe���ɡ�
   ͬ����ȷ������Ҫ��ȡ��Ȩ�ļ�KSInterB2C.lkc��ȷ���ڿ�ִ���ļ�����Ŀ¼����KSInterB2C.lkc
      