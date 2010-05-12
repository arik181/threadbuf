int initconsumer();
int consume()
{
    while(1)
    {
         
        /*** 
         * down(writepending);
         * down(readblock );
         * down mutex1;
         * ++readcount;
         * if (readcount == 1)
         *   down(writeblock)
         * up(mutex1)
         * up(readblock);
         * up(writepending);
         * access(resource);
         * down(mutex1)
         * --readcount;
         * if (readcuont == 0)
         *   up(writeblock);
         *   up(mutex1);
         * ***/
    }
}

