const char* str_ei_class(long long v){
    switch (v){
        case 0:  return "ELFCLASSNONE";
        case 1:  return "ELFCLASS32";
        case 2:  return "ELFCLASS64";
        case 3:  return "ELFCLASSNUM";
        default: printf("Unrecognized ei_class: %lld\n", v);
                 exit(1);
    }
}

const char* str_ei_data(long long v){
    switch (v){
        case 0:     return "ELFDATANONE";
        case 1:     return "ELFDATA2LSB";
        case 2:     return "ELFDATA2MSB";
        case 3:     return "ELFDATANUM";
        default:    printf("Unrecognized ei_data: %lld\n", v);
                    exit(1);
    }
}

const char* str_ei_version(long long v){
    switch (v){
        case 0:     return "EV_NONE";
        case 1:     return "EV_CURRENT";
        case 2:     return "EV_NUM";
        default:    printf("Unrecognized ei_version: %lld\n", v);
                    exit(1);
    }
}

const char* str_ei_osabi(long long v){
    switch (v){
        case 0:     return "ELFOSABI_NONE | ELFOSABI_SYSV";
        case 1:     return "ELFOSABI_HPUX";
        case 2:     return "ELFOSABI_NETBSD";
        case 3:     return "ELFOSABI_GNU | ELFOSABI_LINUX";
        case 6:     return "ELFOSABI_SOLARIS";
        case 7:     return "ELFOSABI_AIX";
        case 8:     return "ELFOSABI_IRIX";
        case 9:     return "ELFOSABI_FREEBSD";
        case 10     return "ELFOSABI_TRU64";
        case 11:    return "ELFOSABI_MODESTO";
        case 12:    return "ELFOSABI_OPENBSD";
        case 64:    return "ELFOSABI_ARM_AEABI";
        case 97:    return "ELFOSABI_ARM";
        case 255:   return "ELFOSABI_STANDALONE";
        default:    printf("Unrecognized ei_osabi: %lld\n", v);
                    exit(1);
    }
}

const char* str_e_type(long long v){
    switch (v){
        case 0:     return "ET_NONE";
        case 1:     return "ET_REL";
        case 2:     return "ET_EXEC";
        case 3:     return "ET_DYN";
        case 4:     return "ET_CORE";
        case 65024: return "ET_LOOS";
        case 65279: return "ET_HIOS";
        case 65280: return "ET_LOPROC";
        case 65535: return "ET_HIPROC";
        default:    printf("Unrecognized e_type: %lld\n", v);
                    exit(1);
    }
}

const char* str_e_machine(long long v){
    switch (v){
        case 0:     return "EM_NONE";
        case 1:     return "EM_M32";
        case 2:     return "EM_SPARC";
        case 3:     return "EM_386";
        case 4:     return "EM_68K";
        case 5:     return "EM_88K";
        case 6:     return "EM_IAMCU";
        case 7:     return "EM_860";
        case 8:     return "EM_MIPS";
        case 9:     return "EM_S370";
        case 10:    return "EM_MIPS_RS3_LE";
        case 15:    return "EM_PARISC";
        case 17:    return "EM_VPP500";
        case 18:    return "EM_SPARC32PLUS";
        case 19:    return "EM_960";
        case 20:    return "EM_PPC";
        case 21:    return "EM_PPC64";
        case 22:    return "EM_S390";
        case 23:    return "EM_SPU";
        case 36:    return "EM_V800";
        case 37:    return "EM_FR20";
        case 38:    return "EM_RH32";
        case 39:    return "EM_RCE";
        case 40:    return "EM_ARM";
        case 41:    return "EM_FAKE_ALPHA";
        case 42:    return "EM_SH";
        case 43:    return "EM_SPARCV9";
        case 44:    return "EM_TRICORE";
        case 45:    return "EM_ARC";
        case 46:    return "EM_H8_300";
        case 47:    return "EM_H8_300H";
        case 48:    return "EM_H8S";
        case 49:    return "EM_H8_500";
        case 50:    return "EM_IA_64";
        case 51:    return "EM_MIPS_X";
        case 52:    return "EM_COLDFIRE";
        case 53:    return "EM_68HC12";
        case 54:    return "EM_MMA";
        case 55:    return "EM_PCP";
        case 56:    return "EM_NCPU";
        case 57:    return "EM_NDR1";
        case 58:    return "EM_STARCORE";
        case 59:    return "EM_ME16";
        case 60:    return "EM_ST100";
        case 61:    return "EM_TINYJ";
        case 62:    return "EM_X86_64";
        case 63:    return "EM_PDSP";
        case 64:    return "EM_PDP10";
        case 65:    return "EM_PDP11";
        case 66:    return "EM_FX66";
        case 67:    return "EM_ST9PLUS";
        case 68:    return "EM_ST7";
        case 69:    return "EM_68HC16";
        case 70:    return "EM_68HC11";
        case 71:    return "EM_68HC08";
        case 72:    return "EM_68HC05";
        case 73:    return "EM_SVX";
        case 74:    return "EM_ST19";
        case 75:    return "EM_VAX";
        case 76:    return "EM_CRIS";
        case 77:    return "EM_JAVELIN";
        case 78:    return "EM_FIREPATH";
        case 79:    return "EM_ZSP";
        case 80:    return "EM_MMIX";
        case 81:    return "EM_HUANY";
        case 82:    return "EM_PRISM";
        case 83:    return "EM_AVR";
        case 84:    return "EM_FR30";
        case 85:    return "EM_D10V";
        case 86:    return "EM_D30V";
        case 87:    return "EM_V850";
        case 88:    return "EM_M32R";
        case 89:    return "EM_MN10300";
        case 90:    return "EM_MN10200";
        case 91:    return "EM_PJ";
        case 92:    return "EM_OPENRISC";
        case 93:    return "EM_ARC_COMPACT | EM_ARC_A5";
        case 94:    return "EM_XTENSA";
        case 95:    return "EM_VIDEOCORE";
        case 96:    return "EM_TMM_GPP";
        case 97:    return "EM_NS32K";
        case 98:    return "EM_TPC";
        case 99:    return "EM_SNP1K";
        case 100:   return "EM_ST200";
        case 101:   return "EM_IP2K";
        case 102:   return "EM_MAX";
        case 103:   return "EM_CR";
        case 104:   return "EM_F2MC16";
        case 105:   return "EM_MSP430";
        case 106:   return "EM_BLACKFIN";
        case 107:   return "EM_SE_C33";
        case 108:   return "EM_SEP";
        case 109:   return "EM_ARCA";
        case 110:   return "EM_UNICORE";
        case 111:   return "EM_EXCESS";
        case 112:   return "EM_DXP";
        case 113:   return "EM_ALTERA_NIOS2";
        case 114:   return "EM_CRX";
        case 115:   return "EM_XGATE";
        case 116:   return "EM_C166";
        case 117:   return "EM_M16C";
        case 118:   return "EM_DSPIC30F";
        case 119:   return "EM_CE";
        case 120:   return "EM_M32C";
        case 131:   return "EM_TSK3000";
        case 132:   return "EM_RS08";
        case 133:   return "EM_SHARC";
        case 134:   return "EM_ECOG2";
        case 135:   return "EM_SCORE7";
        case 136:   return "EM_DSP24";
        case 137:   return "EM_VIDEOCORE3";
        case 138:   return "EM_LATTICEMICO32";
        case 139:   return "EM_SE_C17";
        case 140:   return "EM_TI_C6000";
        case 141:   return "EM_TI_C2000";
        case 142:   return "EM_TI_C5500";
        case 143:   return "EM_TI_ARP32";
        case 144:   return "EM_TI_PRU";
        case 160:   return "EM_MMDSP_PLUS";
        case 161:   return "EM_CYPRESS_M8C";
        case 162:   return "EM_R32C";
        case 163:   return "EM_TRIMEDIA";
        case 164:   return "EM_QDSP6";
        case 165:   return "EM_8051";
        case 166:   return "EM_STXP7X";
        case 167:   return "EM_NDS32";
        case 168:   return "EM_ECOG1X";
        case 169:   return "EM_MAXQ30";
        case 170:   return "EM_XIMO16";
        case 171:   return "EM_MANIK";
        case 172:   return "EM_CRAYNV2";
        case 173:   return "EM_RX";
        case 174:   return "EM_METAG";
        case 175:   return "EM_MCST_ELBRUS";
        case 176:   return "EM_ECOG16";
        case 177:   return "EM_CR16";
        case 178:   return "EM_ETPU";
        case 179:   return "EM_SLE9X";
        case 180:   return "EM_L10M";
        case 181:   return "EM_K10M";
        case 183:   return "EM_AARCH64";
        case 185:   return "EM_AVR32";
        case 186:   return "EM_STM8";
        case 187:   return "EM_TILE64";
        case 188:   return "EM_TILEPRO";
        case 189:   return "EM_MICROBLAZE";
        case 190:   return "EM_CUDA";
        case 191:   return "EM_TILEGX";
        case 192:   return "EM_CLOUDSHIELD";
        case 193:   return "EM_COREA_1ST";
        case 194:   return "EM_COREA_2ND";
        case 195:   return "EM_ARC_COMPACT2";
        case 196:   return "EM_OPEN8";
        case 197:   return "EM_RL78";
        case 198:   return "EM_VIDEOCORE5";
        case 199:   return "EM_78KOR";
        case 200:   return "EM_56800EX";
        case 201:   return "EM_BA1";
        case 202:   return "EM_BA2";
        case 203:   return "EM_XCORE";
        case 204:   return "EM_MCHP_PIC";
        case 210:   return "EM_KM32";
        case 211:   return "EM_KMX32";
        case 212:   return "EM_EMX16";
        case 213:   return "EM_EMX8";
        case 214:   return "EM_KVARC";
        case 215:   return "EM_CDP";
        case 216:   return "EM_COGE";
        case 217:   return "EM_COOL";
        case 218:   return "EM_NORC";
        case 219:   return "EM_CSR_KALIMBA";
        case 220:   return "EM_Z80";
        case 221:   return "EM_VISIUM";
        case 222:   return "EM_FT32";
        case 223:   return "EM_MOXIE";
        case 224:   return "EM_AMDGPU";
        case 243:   return "EM_RISCV";
        case 247:   return "EM_BPF";
        case 252:   return "EM_CSKY";
        case 253:   return "EM_NUM";
        case 36902: return "EM_ALPHA";
        default:    printf("Unrecognized e_machine: %lld\n", v);
                    exit(1);
    }
}

const char* str_e_version(long long v){
    switch (v){
        case 0:     return "EV_NONE";
        case 1:     return "EV_CURRENT";
        case 2:     return "EV_NUM";
        default:    printf("Unrecognized e_version: %lld\n", v);
                    exit(1);
    }
}

const char* str_p_type(long long v){
    switch (v){
        case 1:             return "PT_LOAD";
        case 2:             return "PT_DYNAMIC";
        case 3:             return "PT_INTERP";
        case 4:             return "PT_NOTE";
        case 5:             return "PT_SHLIB";
        case 6:             return "PT_PHDR";
        case 7:             return "PT_TLS";
        case 1610612736:    return "PT_LOOS";
        case 1685382480:    return "PT_GNU_EH_FRAME";
        case 1685382481:    return "PT_GNU_STACK";
        case 1685382482:    return "PT_GNU_RELRO";
        case 1879048186:    return "PT_LOSUNW | PT_SUNWBSS";
        case 1879048187:    return "PT_SUNWSTACK";
        case 1879048191:    return "PT_HISUNW | PT_HIOS";
        case 1879048192:    return "PT_LOPROC | PT_MIPS_REGINFO | PT_PARISC_ARCHEXT";
        case 2147483647:    return "PT_HIPROC";
        case 1879048193:    return "PT_MIPS_RTPROC | PT_PARISC_UNWIND";
        case 1879048194:    return "PT_MIPS_OPTIONS";
        case 1879048195:    return "PT_MIPS_ABIFLAGS";
        default:            printf("Unrecognized p_type: %lld\n", v);
                            exit(1);
    }
}

const char* str_sh_type(long long v){
    switch (v){
        case 0:             return "SHT_NULL";
        case 1:             return "SHT_PROGBITS";
        case 2:             return "SHT_SYMTAB";
        case 3:             return "SHT_STRTAB";
        case 4:             return "SHT_RELA";
        case 5:             return "SHT_HASH";
        case 6:             return "SHT_DYNAMIC";
        case 7:             return "SHT_NOTE";
        case 8:             return "SHT_NOBITS";
        case 9:             return "SHT_REL";
        case 10:            return "SHT_SHLIB";
        case 11:            return "SHT_DYNSYM";
        case 14:            return "SHT_INIT_ARRAY";
        case 15:            return "SHT_FINI_ARRAY";
        case 16:            return "SHT_PREINIT_ARRAY";
        case 17:            return "SHT_GROUP";
        case 18:            return "SHT_SYMTAB_SHNDX";
        case 1610612736:    return "SHT_LOOS";
        case 1879048181:    return "SHT_GNU_ATTRIBUTES";
        case 1879048182:    return "SHT_GNU_HASH";
        case 1879048183:    return "SHT_GNU_LIBLIST";
        case 1879048184:    return "SHT_CHECKSUM";
        case 1879048186:    return "SHT_LOSUNW | SHT_SUNW_move";
        case 1879048187:    return "SHT_SUNW_COMDAT";
        case 1879048188:    return "SHT_SUNW_syminfo";
        case 1879048189:    return "SHT_GNU_verdef";
        case 1879048190:    return "SHT_GNU_verneed";
        case 1879048191:    return "SHT_GNU_versym | SHT_HISUNW | SHT_HIOS";
        case 1879048192:    return "SHT_LOPROC | SHT_MIPS_LIBLIST | SHT_PARISC_EXT";
        case 2147483647:    return "SHT_HIPROC";
        case 2147483648:    return "SHT_LOUSER";
        case 2415919103:    return "SHT_HIUSER";
        case 1879048193:    return "SHT_MIPS_MSYM | SHT_PARISC_UNWIND | SHT_ALPHA_DEBUG | SHT_X86_64_UNWIND";
        case 1879048194:    return "SHT_MIPS_CONFLICT | SHT_PARISC_DOC | SHT_ALPHA_REGINFO";
        case 1879048195:    return "SHT_MIPS_GPTAB";
        case 1879048196:    return "SHT_MIPS_UCODE";
        case 1879048197:    return "SHT_MIPS_DEBUG";
        case 1879048198:    return "SHT_MIPS_REGINFO";
        case 1879048199:    return "SHT_MIPS_PACKAGE";
        case 1879048200:    return "SHT_MIPS_PACKSYM";
        case 1879048201:    return "SHT_MIPS_RELD";
        case 1879048203:    return "SHT_MIPS_IFACE";
        case 1879048204:    return "SHT_MIPS_CONTENT";
        case 1879048205:    return "SHT_MIPS_OPTIONS";
        case 1879048208:    return "SHT_MIPS_SHDR";
        case 1879048209:    return "SHT_MIPS_FDESC";
        case 1879048210:    return "SHT_MIPS_EXTSYM";
        case 1879048211:    return "SHT_MIPS_DENSE";
        case 1879048212:    return "SHT_MIPS_PDESC";
        case 1879048213:    return "SHT_MIPS_LOCSYM";
        case 1879048214:    return "SHT_MIPS_AUXSYM";
        case 1879048215:    return "SHT_MIPS_OPTSYM";
        case 1879048216:    return "SHT_MIPS_LOCSTR";
        case 1879048217:    return "SHT_MIPS_LINE";
        case 1879048218:    return "SHT_MIPS_RFDESC";
        case 1879048219:    return "SHT_MIPS_DELTASYM";
        case 1879048220:    return "SHT_MIPS_DELTAINST";
        case 1879048221:    return "SHT_MIPS_DELTACLASS";
        case 1879048222:    return "SHT_MIPS_DWARF";
        case 1879048223:    return "SHT_MIPS_DELTADECL";
        case 1879048224:    return "SHT_MIPS_SYMBOL_LIB";
        case 1879048225:    return "SHT_MIPS_EVENTS";
        case 1879048226:    return "SHT_MIPS_TRANSLATE";
        case 1879048227:    return "SHT_MIPS_PIXIE";
        case 1879048228:    return "SHT_MIPS_XLATE";
        case 1879048229:    return "SHT_MIPS_XLATE_DEBUG";
        case 1879048230:    return "SHT_MIPS_WHIRL";
        case 1879048231:    return "SHT_MIPS_EH_REGION";
        case 1879048232:    return "SHT_MIPS_XLATE_OLD";
        case 1879048233:    return "SHT_MIPS_PDR_EXCEPTION";
        case 1879048235:    return "SHT_MIPS_XHASH";
        default:            printf("Unrecognized sh_type: %lld\n", v);
                            exit(1);
    }
}

const char* str_st_type(long long v){
    switch (v){
        case 0:             return "STT_NOTYPE";
        case 1:             return "STT_OBJECT";
        case 2:             return "STT_FUNC";
        case 3:             return "STT_SECTION";
        case 4:             return "STT_FILE";
        case 5:             return "STT_COMMON";
        case 6:             return "STT_TLS";
        case 10:            return "STT_LOOS | STT_GNU_IFUNC";
        case 12:            return "STT_HIOS";
        case 13:            return "STT_LOPROC | STT_SPARC_REGISTER | STT_PARISC_MILLICODE | STT_ARM_TFUNC";
        case 15:            return "STT_HIPROC | STT_ARM_16BIT";
        default:            printf("Unrecognized st_type: %lld\n", v);
                            exit(1);
    }
}

const char* str_st_binding(long long v){
    switch (v){
        case 0:     return "STB_LOCAL";
        case 1:     return "STB_GLOBAL";
        case 2:     return "STB_WEAK";
        case 10:    return "STB_LOOS | STB_GNU_UNIQUE";
        case 12:    return "STB_HIOS";
        case 13:    return "STB_LOPROC | STB_MIPS_SPLIT_COMMON";
        case 15:    return "STB_HIPROC";
        default:    printf("Unrecognized st_binding: %lld\n", v);
                    exit(1);
    }
}

const char* str_st_other(long long v){
    switch (v){
        case 0:     return "STV_DEFAULT";
        case 1:     return "STV_INTERNAL";
        case 2:     return "STV_HIDDEN";
        case 3:     return "STV_PROTECTED";
        default:    printf("Unrecognized st_other: %lld\n", v);
                    exit(1);
    }
}

const char* str_relo_type_x86_64(long long v){
    switch (v){
        case 0:     return "R_X86_64_NONE";
        case 1:     return "R_X86_64_64";
        case 2:     return "R_X86_64_PC32";
        case 3:     return "R_X86_64_GOT32";
        case 4:     return "R_X86_64_PLT32";
        case 5:     return "R_X86_64_COPY";
        case 6:     return "R_X86_64_GLOB_DAT";
        case 7:     return "R_X86_64_JUMP_SLOT";
        case 8:     return "R_X86_64_RELATIVE";
        case 9:     return "R_X86_64_GOTPCREL";
        case 10:    return "R_X86_64_32";
        case 11:    return "R_X86_64_32S";
        case 12:    return "R_X86_64_16";
        case 13:    return "R_X86_64_PC16";
        case 14:    return "R_X86_64_8";
        case 15:    return "R_X86_64_PC8";
        case 16:    return "R_X86_64_DTPMOD64";
        case 17:    return "R_X86_64_DTPOFF64";
        case 18:    return "R_X86_64_TPOFF64";
        case 19:    return "R_X86_64_TLSGD";
        case 20:    return "R_X86_64_TLSLD";
        case 21:    return "R_X86_64_DTPOFF32";
        case 22:    return "R_X86_64_GOTTPOFF";
        case 23:    return "R_X86_64_TPOFF32";
        case 24:    return "R_X86_64_PC64";
        case 25:    return "R_X86_64_GOTOFF64";
        case 26:    return "R_X86_64_GOTPC32";
        case 27:    return "R_X86_64_GOT64";
        case 28:    return "R_X86_64_GOTPCREL64";
        case 29:    return "R_X86_64_GOTPC64";
        case 30:    return "R_X86_64_GOTPLT64";
        case 31:    return "R_X86_64_PLTOFF64";
        case 32:    return "R_X86_64_SIZE32";
        case 33:    return "R_X86_64_SIZE64";
        case 34:    return "R_X86_64_GOTPC32_TLSDESC";
        case 35:    return "R_X86_64_TLSDESC_CALL";
        case 36:    return "R_X86_64_TLSDESC";
        case 37:    return "R_X86_64_IRELATIVE";
        case 38:    return "R_X86_64_RELATIVE64";
        case 41:    return "R_X86_64_GOTPCRELX";
        case 42:    return "R_X86_64_REX_GOTPCRELX";
        case 43:    return "R_X86_64_NUM";
        default:    printf("Unrecognized relo_type_x86_64: %lld\n", v);
                    exit(1);
    }
}
