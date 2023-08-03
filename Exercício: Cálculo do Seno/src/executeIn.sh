#!/bin/bash

nameDirIn=In
nameDirOut=MyOut
executableFile=solucao

# Chegando se há um diretório de entrada
[ ! -d $nameDirIn ] && { echo "Error: No \"$nameDirIn\" directory"; exit 1;}


# Se há executará todos os casos

# Descobrindo número de *.in files no diretório
qtt_files=$(ls -1 ./$nameDirIn | wc -l)
echo "[Number of files: $qtt_files]"

# Loop de execução
execute_command="valgrind -s --leak-check=full ./$executableFile" 
for file in $(seq 1 $qtt_files)
do
    echo "File $file"
    # Determinando nome de entrada => ./In/x.in
    in_name=./$nameDirIn/$file.in
    # Determinando nome de saída => myx.out
    out_name=my$file.out

    # Se tiver nome de entrada, executa e salva x.out no diretório ./Out
    if test -f $in_name
        then
            $execute_command <$in_name >$out_name
            # Se o diretório não estiver criado, cria, se não, só insere
            [ -d $nameDirOut ] && mv $out_name ./$nameDirOut || mkdir $nameDirOut | mv $out_name ./$nameDirOut
    fi
    echo "--------------------------------------------------------------------"
done
