time = 0;
while true
    c = [time, randi([1,5],1)*1000, round(rand), randi([1,40],1), round(rand), randi([1,40],1), round(rand), round(rand), round(rand), round(rand)];
    time = time + 1;
    disp(c)
    pause(1)
    fileID=fopen('my_text2.txt','w');
    fprintf(fileID,'%6.0f\n',c');
    fclose(fileID);
end
