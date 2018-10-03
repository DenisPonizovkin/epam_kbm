object KBM: TKBM
  Left = 397
  Top = 183
  Width = 968
  Height = 590
  Caption = 'KBM'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object userInfoLabel: TLabel
    Left = 520
    Top = 32
    Width = 169
    Height = 13
    Caption = 'Input values'
  end
  object GKbmCoef: TDBGrid
    Left = 520
    Top = 128
    Width = 817
    Height = 321
    DataSource = DSKbmCoef
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Visible = False
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'class'
        ImeName = 'class'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'coef'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'payment0'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'payment1'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'payment2'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'payment3'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'payment_over_3'
        Visible = True
      end>
  end
  object BitBtn1: TBitBtn
    Left = 368
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Add contruct'
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 280
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Calucate'
    TabOrder = 2
    OnClick = BitBtn2Click
  end
  object Input: TStringGrid
    Left = 168
    Top = 64
    Width = 321
    Height = 417
    ColCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 3
    ColWidths = (
      64
      100
      140)
  end
  object DSKbmCoef: TDataSource
    DataSet = kbmTable
    Left = 16
    Top = 8
  end
  object ADOCKbmCoef: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=E:\wo' +
      'rk\epam\kbm\kbm_db.mdb;Mode=Share Deny None;Persist Security Inf' +
      'o=False;Jet OLEDB:System database="";Jet OLEDB:Registry Path="";' +
      'Jet OLEDB:Database Password="";Jet OLEDB:Engine Type=5;Jet OLEDB' +
      ':Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=1;Jet' +
      ' OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Passwor' +
      'd="";Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Da' +
      'tabase=False;Jet OLEDB:Don'#39't Copy Locale on Compact=False;Jet OL' +
      'EDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False'
    ConnectOptions = coAsyncConnect
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 112
    Top = 8
  end
  object kbmTable: TADOTable
    Active = True
    Connection = ADOCKbmCoef
    CursorType = ctStatic
    TableName = 'kbm_coefs_class'
    Left = 64
    Top = 8
  end
end
