ע�⣺ò��gitû�а�lib��dll�ļ��ϴ���github�������Ҫ�Լ����ֶ���һ��ɡ�

���û�����Ҫ�㣺
1 ���ú�include��lib��·����������$(ProjectDir)�����������
2 ��linker ��System�е�SubSystem ��console�ĳ�window������������console���ڲ���������
3 ��dll�ļ��ŵ���exe�ļ�ͬһ��Ŀ¼��
4 ע��configuration��64����x86
5 ����SDL imageʱ��Ҫ�����У�4�����ϣ���dll�ļ������Ƶ�ִ��Ŀ¼����У���Ȼ����pngʱ�Ȳ�����Ҳ�޷���ʾͼƬ

��̨Ӧ����ô����
��handle������Ҫ��������������Ϣ����ô�������ˣ��������������Ļ��Ƿ������ص�������˵���������̱߳ȽϺã�
�ܵ���˵����������һ���ߵ��������ɶ�Ӧ�����������������ġ�
�ȸ�������ɡ�
�о���Ҫд��AI��˫�˶�ս��snake����Ҫ��maze����������ai����Ҳ���ܸ���mazeѽ��

��ô��ҪŪ���Ĺ��ܾ���ai��д�������ʹ�ã��߳����⣬��ϷҪ����������Լ�һ���ļ���д���ܡ�

������asio���ˣ���Ҫ��ͷ�ļ������Ƶ���Ŀ��Ȼ�����ļ� ������
	#define ASIO_STANDALONE 
	#include <asio.hpp>
�⼸�б����ǰ��ڵ�һλ�ã����ߺ�����Ҫ����include window.h ǰ�棿��
������У��ټ����漸����

#define ASIO_HAS_STD_ADDRESSOF
#define ASIO_HAS_STD_ARRAY
#define ASIO_HAS_CSTDINT
#define ASIO_HAS_STD_SHARED_PTR
#define ASIO_HAS_STD_TYPE_TRAITS

libevent
1 ����ڹ����İ汾��bug�ģ���github�ϵķ���û�У���release ��tagĿ¼�İ汾�����Ժ��ҿ����github����Ҫ�ڹ��������ˣ�������
2 �õ������ĳ��������Ҫ�������� ws2_32.lib wsock32.lib
3 ������������ҳ http://blog.csdn.net/xiaoluer/article/details/56280681
4 ��������õ���vs �Դ���nmake /a /f Makefile.namke ������У�����Ҫcmake�Ȼ�����ڵģ����ܱ�Ŀ�Ҳ��֧��nmake�˰�
