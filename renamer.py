import os
import shutil

def copy_files_with_version(source_dir, dest_dir, prefix):
    # Create the destination directory if it doesn't exist
    os.makedirs(dest_dir, exist_ok=True)

    # List all files in the source directory
    files = os.listdir(source_dir)

    for file in files:
        # Construct the full source file path
        source_file_path = os.path.join(source_dir, file)

        # Make sure it's a file
        if os.path.isfile(source_file_path):

            idx = file.index('.')
            num = (int) (file[:idx])
            ext = (file[idx:])
            
            new_file_name = ""

            if num == 1:
                new_file_name = prefix + "sample_1" + ext
            elif 2 <= num and num <= 4:
                new_file_name = prefix + "2_" + (str) (num - 1) + ext
            elif 5 <= num and num <= 7:
                new_file_name = prefix + "3_" + (str) (num - 4) + ext
            elif 8 <= num and num <= 15:
                new_file_name = prefix + "4_" + (str) (num - 7) + ext
            
            # Construct the full destination file path
            dest_file_path = os.path.join(dest_dir, new_file_name)

            # Copy the file to the destination directory with the new name
            shutil.copy2(source_file_path, dest_file_path)
            print(f'Copied: {file} -> {new_file_name}')

source_dir = "../threesum_gold_jan20"
dest_dir = "./tc"
prefix = "usaco-2020-jan-3sum_"
copy_files_with_version(source_dir, dest_dir, prefix)