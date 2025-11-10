# 🔐 Security Scanning Configuration

This directory contains security scanning configuration for the Media Planning MCP Server.

## 📁 Files Overview

- **`./github/workflows/secret-scanner.yml`** - GitHub Actions workflow for automated security scanning
- **`../security/rules.yml`** - TruffleHog3 detection rules and patterns
- **`../security/.securityignore`** - Files and patterns excluded from security scanning  

## 🚀 Quick Start

### Exclude Files from Scanning

Add patterns to `.securityignore`:
```bash
# Exclude specific files
.github/security/trufflehog-rules.yml
config/example.env

# Exclude by pattern  
**/test/**/*.mock
**/.env.example
```

### Add Custom Rules

Edit `.github/security/rules.yml`:
```yaml
- id: my-service.api-key
  message: My Service API Key
  pattern: "myservice_[a-zA-Z0-9]{32}"
  severity: HIGH
```

## 🔄 Workflow Integration

The security scan automatically:
1. ✅ Scans only changed files in PRs
2. ✅ Excludes files listed in `.securityignore`  
3. ✅ Posts results as PR comments with HTML reports
4. ✅ Fails the build if secrets are detected

## 📊 Current Exclusions

Files automatically excluded from scanning:
- Security rules configuration files (`.github/security/rules.yml`)
- Documentation and README files
- Test fixtures and mock data
- Binary and media files
- Package lock files
- Environment file templates

## 🆘 Troubleshooting

### Too Many False Positives?
- Add specific files to `.securityignore`
- Refine rule patterns to be more specific
- Lower rule severity levels

### Missing Real Secrets?
- Add new patterns to `.github/security/rules.yml`
- Test with anonymized examples
- Review entropy thresholds

### Performance Issues?
- Exclude large binary files
- Optimize regex patterns
- Current setup only scans changed files ✅
---

*Security scanning is automatically triggered on all pull requests to `main` and `dev` branches.*
