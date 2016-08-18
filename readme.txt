readme.txt

--------------------------------------------------
 make sure you set connection and solver

command---- dw get connection

to select laptop---press 1

command----- dw get solver

select sampling

-------------------------------------------------
-------------------------------------------------
to create executable
-------------------------------------------------

qsage -p tsproblem –b optimize –a n:integer:N:0 –a b:integer:a_a:0 -a c:integer:a_b:0 -a d:integer:a_c:0 -a e:integer:a_d:0 -a g:integer:b_a:0 -a h:integer:b_b:0 -a j:integer:b_c:0 -a k:integer:b_d:0 -a l:integer:c_a:0 -a m:integer:c_b:0 -a q:integer:c_c:0 -a r:integer:c_d:0 -a s:integer:d_a:0 -a w:integer:d_b:0 -a x:integer:d_c:0 -a y:integer:d_d:0 \
-i tsproblem_init -o tsproblem_obj -f tsproblem_final \
tsproblem.c

-------------------------------------------------
to run
-------------------------------------------------

tsproblem –v –t 15 –o 0 –E –n 4 -b 1 -c 5 -d 4 -e 2 -g 2 -h 1 -j 5 -k 4 -l 9 -m 6 -q 2 -r 4 -s 7 -w 5 -x 3 -y 4  

-------------------------------------------------
change -t ==> 5, 10, 15......... 