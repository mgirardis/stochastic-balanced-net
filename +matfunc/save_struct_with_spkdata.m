function save_struct_with_spkdata(filename,s_data,spkData)
    fn = fieldnames(s_data);
    for i = 1:numel(fn)
        eval([fn{i},'=s_data.(fn{',num2str(i),'});']);
    end
    neuron_idx_exc = [1,s_data.N_rec_Exc];
    neuron_idx_inh = [s_data.N_rec_Exc+1,s_data.nNeuSpikingData];
    spkData_col_name = 'time,neuron_idx';
    fn = [fn;'neuron_idx_exc';'neuron_idx_inh';'spkData_col_name';'spkData'];
    
    s_data_info = whos('s_data');
    spkData_info = whos('spkData');
    use_v73 = (s_data_info.bytes + spkData_info.bytes) > (2*1024*1024*1024); % the size is greater than 2GB, use v7.3
    
    clearvars s_data
    fprintf(' ... saving ::: %s \n',filename);
    if use_v73
        save(filename,'-v7.3',fn{:});
    else
        save(filename,fn{:});
    end
end