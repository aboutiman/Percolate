clc
clear all
close all

firstL = textread('C:\0-My Computer\Computer\CodeBlocks\MyPro\PercolateTest1\Graphic.txt','%s',1,'delimiter','\n','headerlines',0);
firstL = cell2mat(firstL);
i=1;
n = '';
while firstL(i)~=' '
    n = [n firstL(i)];
    i = i+1;
end
i = i+1;
T = '';
while firstL(i)~=' '
    T = [T firstL(i)];
    i = i+1;
end
nn = str2num(n);
TT = str2num(T);
i=0;
%nn = 100;
pstar = '';
for i=1:TT
    SI = num2str(i);
    opnst = '';
    p = '';
    sum = '';
    X = [0 0 nn nn];
    Y = [0 -nn -nn 0];
    hold on
    fill(X,Y,'k');
    for Ai=1:nn-1
        fill([0 0 nn nn],[-Ai-.02 -Ai+.02 -Ai+.02 -Ai-.02],'w');
        fill([Ai-.01 Ai+.01 Ai+.01 Ai-.01],[0 0 -nn -nn],'w')
    end
    titletext = ['n=' n '   ' 'T=' SI '   ' 'opnst=' ' ' '   ' 'p=' ' ' '   ' 'sum=' sum '   ' 'p*=' pstar];
    title(titletext);
    Li = textread('C:\0-My Computer\Computer\CodeBlocks\MyPro\PercolateTest1\Graphic.txt','%s',1,'delimiter','\n','headerlines',i);
    Li = cell2mat(Li);
    j = 1;
    while Li(j)~='E'
        ii = '';
        jj = '';
        s = '';
        while Li(j)~=' '%i
            ii = [ii Li(j)];
            j = j+1;
        end
        j = j+1;
        while Li(j)~=' '%j
            jj = [jj Li(j)];
            j = j+1;
        end
        j = j+1;
        s = Li(j);
        j = j+2;
        
        I = str2num(ii);
        J = str2num(jj);
        fill([J-1 J-1 J J],[-I+1 -I -I -I+1],s);
        pause(.1);
        
    end
    j = j+2;
    while Li(j)~=' '
        opnst = [opnst Li(j)]; 
        j = j+1;
    end
    j = j+1;
    while Li(j)~=' '
        p = [p Li(j)];
        j = j+1;
    end
    j = j+1;
    while Li(j)~=' '
        sum = [sum Li(j)];
        j = j+1;
    end
    titletext = ['n=' n '   ' 'T=' SI '   ' 'opnst=' opnst '   ' 'p=' p '   ' 'sum=' sum '   ' 'p*=' ' '];
    title(titletext);
    pause(4)
end

lastL = textread('C:\0-My Computer\Computer\CodeBlocks\MyPro\PercolateTest1\Graphic.txt','%s',1,'delimiter',' ','headerlines',TT+1);
lastL = cell2mat(lastL);
pstar = lastL;
titletext = ['n=' n '   ' 'T=' T '   ' 'opnst=' opnst '   ' 'p=' p '   ' 'sum=' sum '   ' 'p*=' pstar];
title(titletext);
pause(10)
