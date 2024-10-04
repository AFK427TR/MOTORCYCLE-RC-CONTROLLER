ENG/TR

EN:
Thanks to any 433 Mhz remote control and Arduino, you can start your engine without touching it.

Parts you need to replace later:

1_You need to change the k_1 k_2 and k_3 variables according to the values ​​given by the remote control you have.
  You can look at the test code in my account to measure this.
  
2_You need to measure how many seconds it takes to crank your engine, but most motorcycles run for about 300 ms.

3_You can adjust the speed of the flashes according to your needs, I used 50 ms and 300 ms as an example.

İmportant:
You need to download the RCSwitch library

It is recommended to add a delay so that it does not detect 2 commands when you press the remote control.

enjoy!

TR:
Herhangi bir 433 Mhz uzaktan kumanda ve Arduino sayesinde motorunuzu dokunmadan çalıştırabilirsiniz.

Daha sonra değiştirmeniz gereken kod kısımları:

1_ K_1 k_2 ve k_3 değişkenlerini sahip olduğunuz 433 mhz kumandanın verdiği değerlere göre değiştirmeniz gerekmektedir.
   Bunu ölçmek için hesabımdaki test koduna bakabilirsiniz
   
2_Motorunuzu çalıştırmanın kaç saniye sürdüğünü ölçmeniz gerekir, ancak çoğu motosiklet yaklaşık 300 ms marş ile çalışır.

3_Çakarların hızını zevkinize göre ayarlayabilirsiniz, örnek olarak 50 ms ve 300 ms kullandım.

Önemli:
RCSwitch kütüphanesini indirmeniz gerekiyor

Uzaktan kumandaya bastığınızda aynı anda 2 komutu algılamaması için gecikme eklenmesi önerilir.

İyi eğlenceler!
