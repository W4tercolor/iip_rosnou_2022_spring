object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 268
  ClientWidth = 266
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelCurrent: TLabel
    Left = 133
    Top = 200
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label2: TLabel
    Left = 8
    Top = 247
    Width = 32
    Height = 13
    Caption = #1042#1089#1077#1075#1086':'
  end
  object LabelCount: TLabel
    Left = 52
    Top = 247
    Width = 13
    Height = 13
    Caption = '0'
  end
  object LabelOrder: TLabel
    Left = 30
    Top = 71
    Width = 74
    Height = 13
    Caption = ' '#1053#1086#1084#1077#1088'_'#1079#1072#1082#1072#1079#1072
  end
  object LabelName: TLabel
    Left = 30
    Top = 98
    Width = 23
    Height = 13
    Caption = #1060#1048#1054
  end
  object LabelPhone: TLabel
    Left = 31
    Top = 152
    Width = 44
    Height = 13
    Caption = #1058#1077#1083#1077#1092#1086#1085
  end
  object LabelAddress: TLabel
    Left = 31
    Top = 125
    Width = 34
    Height = 13
    Caption = #1040#1076#1088#1077#1089' '
  end
  object ButtonRight: TButton
    Left = 147
    Top = 195
    Width = 36
    Height = 25
    Caption = '>'
    TabOrder = 0
    OnClick = ButtonRightClick
  end
  object ButtonLeft: TButton
    Left = 93
    Top = 195
    Width = 34
    Height = 25
    Caption = '<'
    TabOrder = 1
    OnClick = ButtonLeftClick
  end
  object EditOrder: TEdit
    Left = 117
    Top = 68
    Width = 132
    Height = 21
    TabOrder = 2
  end
  object EditName: TEdit
    Left = 72
    Top = 95
    Width = 177
    Height = 21
    TabOrder = 3
  end
  object EditAddress: TEdit
    Left = 71
    Top = 122
    Width = 178
    Height = 21
    TabOrder = 4
  end
  object EditPhone: TEdit
    Left = 93
    Top = 149
    Width = 156
    Height = 21
    TabOrder = 5
  end
  object ButtonAdd: TButton
    Left = 52
    Top = 28
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 6
    OnClick = ButtonAddClick
  end
  object ButtonDelete: TButton
    Left = 147
    Top = 28
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 7
  end
end
