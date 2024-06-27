#include "Installer.h"

std::wstring Installer::OpenFolderDialog(const std::wstring& defaultPath) {
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(hr)) {
        IFileDialog* pfd = NULL;
        hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pfd));

        if (SUCCEEDED(hr)) {
            DWORD dwOptions;
            pfd->GetOptions(&dwOptions);
            pfd->SetOptions(dwOptions | FOS_PICKFOLDERS);

            IShellItem* psiFolder = NULL;
            hr = SHCreateItemFromParsingName(defaultPath.c_str(), NULL, IID_PPV_ARGS(&psiFolder));
            if (SUCCEEDED(hr)) {
                pfd->SetFolder(psiFolder);
                psiFolder->Release();
            }

            hr = pfd->Show(NULL);

            if (SUCCEEDED(hr)) {
                IShellItem* psiResult;
                hr = pfd->GetResult(&psiResult);

                if (SUCCEEDED(hr)) {
                    PWSTR pszFilePath = NULL;
                    hr = psiResult->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

                    if (SUCCEEDED(hr)) {
                        std::wstring ws(pszFilePath);
                        CoTaskMemFree(pszFilePath);
                        psiResult->Release();
                        pfd->Release();
                        CoUninitialize();

                        return ws;
                    }
                    psiResult->Release();
                }
            }
            pfd->Release();
        }
        CoUninitialize();
    }
    return std::wstring(L"");
}

std::wstring Installer::GetLocalAppDataPath()
{
    PWSTR localAppDataPath = NULL; 
    HRESULT hr = SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &localAppDataPath);
    if (SUCCEEDED(hr)) {
        std::wstring path(localAppDataPath);
        CoTaskMemFree(localAppDataPath);
        return path;
    }
    return L"";
}

