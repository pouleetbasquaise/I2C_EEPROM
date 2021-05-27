#include <i2c.h>

long int adress;
long int value;
int data;
void write(long int adress, int data);
int read(long int adress);
/*void suppMemoire()
   {
      for (i = 0; i<128; i++)
         {
         write(i,0);
         delay_ms(100);
         }
   }*/


void main()
   {
      usb_init();
while(TRUE)
       {      
   if(usb_cdc_kbhit()==1)
           {
            char recu;
            recu = usb_cdc_getc();
            if(recu =='w')
               {
                  printf(usb_cdc_putc,"tu as ecris w \n\r");
                  delay_ms(50);
                  printf(usb_cdc_putc,"A quelle adresse ? \n\r");
                  scanf(usb_cdc_getc,"%Ld",&adress);
                  printf (usb_cdc_putc,"Quelle donnee ? \n\r");
                  scanf(usb_cdc_getc,"%Ld",&data);
                  write (adress,data);
               }
            else if (recu =='r')
               {
                  printf(usb_cdc_putc,"tu as ecris r \n\r");
                  delay_ms(50);
                  printf(usb_cdc_putc,"qu'elle adresse ?\n\r");
                  scanf(usb_cdc_getc,"%Ld",&adress);
                  value = read(adress);
                  printf(usb_cdc_putc,"%Ld \n\r",value);
               }
         }
      }



  // long int adress;
   //printf("bonjours \n\r");
  // long int value;
  // int data;


 /*        if(kbhit()==1)
           {
            char recu;
            recu = getc();
            if(recu =='w')
               {
                  printf("tu as ecris w \n\r");
                  delay_ms(50);
                  printf("A quelle adresse ? \n\r");
                  scanf("%Ld",&adress);
                  printf ("Quelle donnee ? \n\r");
                  scanf("%Ld",&data);
                  write (adress,data);
               }
            else if (recu =='r')
               {
                  printf("tu as ecris r \n\r");
                  delay_ms(50);
                  printf("qu'elle adresse ?\n\r");
                  scanf("%Ld",&adress);
                  value = read(adress);
                  printf("%Ld \n\r",value);
               }
         }*/
      }





void write(long int adress, int DataW)//void permettant d'écrire dans la mémoire
      {
         int adress_device = 0b10100000;
         i2c_start();
         delay_ms(50);
         i2c_write(adress_device);
         delay_ms(50);
         int adressH=adress>>8;
         int adressL=adress;

         i2c_write(adressH);
         i2c_write(adressL);
         i2c_write(DataW);
         i2c_stop();
      }


int read(long int adress)//fonction permettant de lire dans la mémoire ce que l'utilisateur à écrit
      {
      int DataR;
         i2c_start();
         i2c_write(0b10100000);
         int adressH=adress>>8;
         int adressL=adress;
         i2c_write(adressH);
         i2c_write(adressL);
         i2c_start();
         i2c_write(0b10100001);
         DataR=i2c_read(0);

         delay_ms(50);
         i2c_stop();

         return DataR;
      }




