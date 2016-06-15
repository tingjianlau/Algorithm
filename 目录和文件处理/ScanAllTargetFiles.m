function [filesAbsPathCell] = ScanAllFormatFiles( sorceFloder, format, includeCurrentFolder)
% ScanAllImg Scan and return the list of specified format files.
% sorceFloder: the absolute path of target folder
% format: the format of file.
% includeCurrentFolder: indicate whether scanning files under the current
% floder, 0 or 1.
% filesAbsPathCell: the return variable, cell.
if nargin == 2
    includeCurrentFolder = 0;
elseif nargin < 2
    error('Not Enough Input Arguments.');
end

if(find(sorceFloder(:) == '/')) % The operating system, WINDOWS or LINUX, path delimiter
    delimiter = '/';
else
    delimiter = '\';
end

% Scan the sorceFloder and gain the all files and subfolders under the sorceFloder
sourceDirList = dir(sorceFloder);
folderCell = cell(1,1);
ff = 1;
for i=1:length(sourceDirList)
    if(sourceDirList(i).isdir==1&&~strcmp(sourceDirList(i).name,'..'))  % include the current folder and its subfolders
        folderCell{ff}=[sourceDirList(i).name]; %
        ff=ff+1;
    end
end

% Check whether including the current folder
if(includeCurrentFolder == 0)
    folderCell(strcmp(folderCell(:),  '.')) = [];
end

filesAbsPathCell = cell(1,0);
f = 1;

% Scan each subfolder and return the all specified format files
for i = 1:length(folderCell)
    fileList = dir(strcat(sorceFloder, folderCell{i}, delimiter, '*.', format));
    for j=1:length(fileList)
        filesAbsPathCell{f} = strcat(sorceFloder,folderCell{i}, delimiter, fileList(j).name);
        f = f + 1;
    end
end
end
