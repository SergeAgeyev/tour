inherited TourTripOwnerSimpleAddForm: TTourTripOwnerSimpleAddForm
  Caption = '����� ����������'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = '������'
  end
  inherited OkButton: TButton
    Caption = '���������'
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      '�������� �� �������� ��������� ������ ����'
      '��� ��������� �������� ������ ���� ���� Integer'
      '�������� �� �������� ��������� �������� ����'
      '��� ��������� �������� ������ ���� ���� Float'
      '������� ��� �����������'
      
        '���� "��� �����������" �������� ��������. ��� ����������� ������' +
        '�����.'
      '���������� � ����� ����� ��� ����������.'
      
        '���� "��� �����������" �������� ������������ �������� �����. ���' +
        ' ��������  ������ ���� ���������.')
  end
end
