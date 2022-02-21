function mat_file = get_corresponding_mat_file(txt_file_path)
    mat_file = regexprep(txt_file_path,'_spkdata\.txt$','.mat');
end