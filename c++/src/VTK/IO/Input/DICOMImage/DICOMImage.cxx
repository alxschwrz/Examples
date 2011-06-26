#include <vtkSmartPointer.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkPolyData.h>
#include <vtkImageData.h>
#include <vtkSmartPointer.h>
#include <vtkDICOMImageReader.h>
#include <vtkXMLImageDataWriter.h>

int main(int argc, char *argv[])
{
  if(argc != 3)
    {
    vtkstd::cout << "Required arguments: InputFilename OutputFilename" << vtkstd::endl;
    exit(-1);
    }
  
  vtkstd::string InputFilename = argv[1];
  vtkstd::string OutputFilename = argv[2];
  
  vtkSmartPointer<vtkDICOMImageReader> DICOMreader = vtkSmartPointer<vtkDICOMImageReader>::New();
  DICOMreader->SetFileName(InputFilename.c_str());
  DICOMreader->Update();
  
  vtkSmartPointer<vtkXMLImageDataWriter> writer = vtkSmartPointer<vtkXMLImageDataWriter>::New();
  writer->SetInput(DICOMreader->GetOutput());
  
  writer->SetFileName(OutputFilename.c_str());
  writer->Update();
  
  return 0;
}