clearvars
close all

txt_files = dir('./output_close_gc/*_spkdata.txt');

for i = 1:numel(txt_files)
    fn_txt = fullfile(txt_files(i).folder,txt_files(i).name);
    fn_mat = matfunc.get_corresponding_mat_file(fn_txt);
    out_fn = regexprep(fn_txt,'_spkdata\.txt$','_full.mat');

    if exist(out_fn,'file')
        fprintf('file %s already exist\n',out_fn);
        continue;
    end
    
    fprintf('Loading ::: %s \n',fn_mat);
    s_data = load(fn_mat);
    fprintf(' ... loading ::: %s \n',fn_txt);
    spkData = uint32(importdata(fn_txt,',',0));
    matfunc.save_struct_with_spkdata(out_fn,s_data,spkData);
    clearvars s_data spkData
    delete(fn_txt);
    delete(fn_mat);
end
